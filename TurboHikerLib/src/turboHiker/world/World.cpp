//
// Created by RobMa on 19/12/2020.
//

#include "World.h"
#include <cassert>

#include "Command.h"
#include "Hiker.h"
#include "Random.h"
#include "Renderer.h"
#include "Score.h"
#include "Transformation.h"

#include <EventObserver.h>
#include <set>

using namespace turboHiker;

turboHiker::World::World(const BoundingBox& worldBorders)
    : mWorldBorders(worldBorders), mPreviousLaneEnemySpawned(0), mHikeStatus(HikeStatus::BeforeHiking), mHighscores(3),
      mScore(std::make_shared<Score>(300, 5, 5000, std::chrono::duration<double>(30)))
{
        addObserver(mScore);
}

void World::update(Updatable::seconds dt)
{

        if (mHikeStatus == HikeStatus::WhilstHiking) {
                generateCompetingHikers(dt);
        }

        mSceneGraph.update(dt);

        // Update the center of view so the player is tracked in the middle
        trackPlayer();

        // Now update the render components. Make sure to update it after the Transformation singleton has altered its
        // view (due to trackPlayer).
        mSceneGraph.updateRenderComponents(dt);

        while (!mCommandQueue.isEmpty()) {
                Command command = mCommandQueue.pop();
                onCommand(command, dt);
        }

        if (mHikeStatus == HikeStatus::WhilstHiking) {
                handleCollisions();

                removeCompetingHikers();
                mSceneGraph.cleanupDeadObjects();
        }
}

void World::render() const { mSceneGraph.render(); }

void World::onCommand(const Command& command, Updatable::seconds dt)
{
        if (command.whenToExecute & mHikeStatus) {
                if (command.category == GameCategory::GameWorld) {
                        command.action(*this, dt);
                } else {
                        assert((!(command.category & GameCategory::GameWorld)) &&
                               "World should be an only category and may not be included within other categories");
                        mSceneGraph.onCommand(command, dt);
                }
        }
}

void turboHiker::World::buildWorld(int nrLanes)
{
        assert(mSceneNodeFactory != nullptr && "SceneNode Factory not set: no way to create new SceneNodes");

        mSceneGraph.clear();

        for (int lane = 0; lane < nrLanes + 0; lane++) {
                SceneNode currentLane = mSceneNodeFactory->createLane(
                    BoundingBox(getWorldBorders().getLeft() + getWorldBorders().getWidth() / nrLanes * lane,
                                getWorldBorders().getBottom(), getWorldBorders().getWidth() / nrLanes,
                                getWorldBorders().getHeight()));

                mSceneGraph.addLane(currentLane);
        }

        mSceneGraph.setFinish(mSceneNodeFactory->createFinish(BoundingBox(
            getWorldBorders().getLeft(), getWorldBorders().getTop() - 100, getWorldBorders().getWidth(), 100)));

        mSceneGraph.setPlayerHiker(mSceneNodeFactory->createPlayerHiker(10, Vector2d(20, 20), 50, 350));

        putHikerOnLane(mSceneGraph.getPlayerHiker(), 2, true);

        mPreviousLaneEnemySpawned =
            static_cast<int>(std::round(Random::get().randomNumber() * (mSceneGraph.getAmountOfLanes() - 1)));

        mHikeStatus = HikeStatus::BeforeHiking;
}

void World::generateCompetingHikers(seconds dt)
{

        double playerSight =
            Transformation::get().getWorldViewCenter().y + Transformation::get().getWorldView().getWorldViewHeight();

        // We want the enemies to spawn on the fly as the player moves

        // The higher this number is, the more enemies will spawn per time unit. If the player is going fast, more
        // enemies will spawn proportionally to the player's 'fast' speed versus the slow.
        double spawnRate =
            2 *
            (getPlayerHiker().goingFast() ? (getPlayerHiker().getFastSpeed() / getPlayerHiker().getSlowSpeed()) : 1) *
            dt.count();
        //        assert(spawnRate >= 0 && spawnRate <= 1);

        bool enemyShouldSpawn = false;
        double randomNumber = Random::get().randomNumber();

        // An enemy should spawn
        if (randomNumber < spawnRate) {
                enemyShouldSpawn = true;
        }

        if (enemyShouldSpawn) {

                int chosenLane;

                do {
                        chosenLane =
                            static_cast<int>(Random::get().randomNumber() * (mSceneGraph.getAmountOfLanes() - 0.01));
                } while (chosenLane == mPreviousLaneEnemySpawned);

                assert(chosenLane >= 0 && chosenLane < mSceneGraph.getAmountOfLanes());

                Vector2d size(20, 20);
                double yLocation = playerSight + size.y;
                double xLocation = mSceneGraph.getLane(chosenLane).getLocation().x;

                if (xLocation >= mWorldBorders.getLeft() && xLocation <= mWorldBorders.getRight() &&
                    yLocation >= mWorldBorders.getBottom() && yLocation <= mWorldBorders.getTop()) {
                        if (!mSceneGraph.spaceOccupiedBy(
                                BoundingBox(xLocation - size.x / 2, yLocation - size.y / 2, size.x, size.y),
                                GameCategory::GameStaticHiker) &&
                            !mSceneGraph.spaceOccupiedBy(
                                BoundingBox(xLocation - size.x / 2, yLocation - size.y / 2, size.x, size.y),
                                GameCategory::GameFinish)) {

                                // If true, spawn a static hiker, false: spawn a moving hiker
                                bool spawnStatic = Random::get().randomNumber() < 0.2;

                                if (spawnStatic) {
                                        StaticHiker hiker = mSceneNodeFactory->createStaticHiker(yLocation, size);
                                        putHikerOnLane(hiker, chosenLane, true);
                                        mSceneGraph.addStaticHiker(hiker);
                                } else {
                                        RunningHiker hiker =
                                            mSceneNodeFactory->createMovingHiker(yLocation, size, Vector2d(0, -300));
                                        putHikerOnLane(hiker, chosenLane, true);
                                        mSceneGraph.addRunningHiker(hiker);
                                }
                        }
                }

                mPreviousLaneEnemySpawned = chosenLane;
        }
}

void World::removeCompetingHikers()
{

        double outOfViewYCoord =
            Transformation::get().getWorldViewCenter().y - Transformation::get().getWorldView().getWorldViewHeight();

        for (int i = 0; i < mSceneGraph.getAmountOfCompetingHikers(); i++) {
                Hiker& competingHiker = mSceneGraph.getCompetingHiker(i);

                // If the hikers fall out of the world, it is time to remove them
                if (competingHiker.getLocation().y - competingHiker.getSize().y < outOfViewYCoord) {
                        competingHiker.markForRemoval();
                }
        }
}

void World::trackPlayer() const
{

        double newWorldViewCenterX;
        double newWorldViewCenterY = Transformation::get().getWorldViewCenter().y;

        if (Transformation::get().getWorldView().getWorldViewWidth() >= mWorldBorders.getWidth()) {
                newWorldViewCenterX = getWorldBorders().getWidth() / 2;
        } else {
                newWorldViewCenterX = mSceneGraph.getPlayerHiker().getLocation().x;
        }

        if (mSceneGraph.getPlayerHiker().getLocation().y > Transformation::get().getWorldViewCenter().y) {
                newWorldViewCenterY = mSceneGraph.getPlayerHiker().getLocation().y;
        }

        Transformation::get().setWorldViewCenter(Vector2d(newWorldViewCenterX, newWorldViewCenterY));
}

bool World::matchesCategories(SceneGraph::SceneNodePair& sceneNodePair, GameCategory type1, GameCategory type2)
{
        unsigned int category1 = sceneNodePair.first->getCategory();
        unsigned int category2 = sceneNodePair.second->getCategory();

        // Make sure first pair entry has category type1 and second has type2
        if (type1 & category1 && type2 & category2) {
                return true;
        } else if (type1 & category2 && type2 & category1) {
                std::swap(sceneNodePair.first, sceneNodePair.second);
                return true;
        } else {
                return false;
        }
}

void turboHiker::World::handleCollisions()
{
        std::set<SceneGraph::SceneNodePair> collisionPairs = mSceneGraph.findCollisionPairs();

        for (auto pair : collisionPairs) {

                if (matchesCategories(pair, GameCategory::GamePlayerHiker, GameCategory::GameStaticHiker) ||
                    matchesCategories(pair, GameCategory::GamePlayerHiker, GameCategory::GameRunningHiker)) {

                        std::shared_ptr<Hiker> playerHiker = std::static_pointer_cast<Hiker>(pair.first);

                        const std::shared_ptr<Hiker>& otherHiker = std::static_pointer_cast<Hiker>(pair.second);

                        otherHiker->markForRemoval();
                        notify(Event::PLAYER_COLLIDED);

                } else if (matchesCategories(pair, GameCategory::GameStaticHiker, GameCategory::GameRunningHiker)) {

                        pair.first->markForRemoval();

                } else if (matchesCategories(pair, GameCategory::GamePlayerHiker, GameCategory::GameFinish)) {
                        endHike();
                }
        }
}

void turboHiker::World::setEntityFactory(std::unique_ptr<SceneNodeFactory> entityFactory)
{
        assert(mSceneNodeFactory == nullptr && "Entity factory can only be set once");
        mSceneNodeFactory = std::move(entityFactory);
}

turboHiker::CommandQueue& turboHiker::World::getCommandQueue() { return mCommandQueue; }
const turboHiker::BoundingBox& turboHiker::World::getWorldBorders() const { return mWorldBorders; }

PlayerHiker& World::getPlayerHiker() const { return mSceneGraph.getPlayerHiker(); }

void World::putHikerOnLane(Hiker& hiker, int laneIndex, bool instantly)
{

        assert(laneIndex < getAmountOfLanes() && laneIndex >= 0);
        SceneNode& lane = mSceneGraph.getLane(laneIndex);

        if (instantly) {
                hiker.setLocation(Vector2d(lane.getLocation().x, hiker.getLocation().y));
        } else {
                hiker.setDestinationX(lane.getLocation().x);
        }
        hiker.setCurrentLane(laneIndex);
}

void World::hikerYelled(Hiker& hiker, double yellDistance)
{

        int closestHikerToYellAtIndex = -1;
        for (int currentHikerIndex = 0; currentHikerIndex < mSceneGraph.getAmountOfCompetingHikers();
             currentHikerIndex++) {

                Hiker& currentHiker = mSceneGraph.getCompetingHiker(currentHikerIndex);

                if (currentHiker.getCurrentLane() == hiker.getCurrentLane() && !currentHiker.isMarkedForRemoval() &&
                    currentHiker.getLocation().y > hiker.getLocation().y &&
                    currentHiker.getLocation().y - hiker.getLocation().y < yellDistance) {

                        if (closestHikerToYellAtIndex != -1) {
                                Hiker& currentClosestHiker = mSceneGraph.getCompetingHiker(closestHikerToYellAtIndex);

                                // The current closest hiker is further away than the current hiker you are iterating
                                // over, so replace the current closest hiker
                                if (currentClosestHiker.getLocation().y > currentHiker.getLocation().y) {
                                        closestHikerToYellAtIndex = currentHikerIndex;
                                }
                        } else {
                                closestHikerToYellAtIndex = currentHikerIndex;
                        }
                }
        }

        if (closestHikerToYellAtIndex != -1) {

                Hiker& hikerToYellAt = mSceneGraph.getCompetingHiker(closestHikerToYellAtIndex);
                hikerToYellAt.onYelledAt();
                notify(Event::YELLED_AT_HIKER);
        }
}

unsigned int World::getAmountOfLanes() const { return mSceneGraph.getAmountOfLanes(); }
HikeStatus World::getHikeStatus() const { return mHikeStatus; }

unsigned int World::getAmountOfCompetingHikers() const { return mSceneGraph.getAmountOfCompetingHikers(); }

void World::startHiking()
{
        assert(mHikeStatus == HikeStatus::BeforeHiking);
        notify(Event::PLAYER_STARTED);
        mHikeStatus = HikeStatus::WhilstHiking;
}

void World::resetHike(bool saveHighScore)
{
        buildWorld(static_cast<int>(mSceneGraph.getAmountOfLanes()));
        Transformation::get().setWorldViewCenterY(Transformation::get().getWorldView().getWorldViewHeight() / 2);

        if (saveHighScore) {
                mHighscores.addScore(*mScore);
        }
        mScore->reset();
}

void World::endHike()
{
        mHikeStatus = HikeStatus::AfterHiking;
        notify(Event::PLAYER_FINISHED);
        mSceneGraph.getPlayerHiker().setVelocity(Vector2d(0, 0));
}

const Score& World::getScore() const { return *mScore; }
const HighScoreContainer& World::getHighScores() const { return mHighscores; }
