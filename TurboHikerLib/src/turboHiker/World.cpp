//
// Created by RobMa on 19/12/2020.
//

#include "World.h"
#include <cassert>

#include "CollisionComponent.h"
#include "Hiker.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "Random.h"
#include "SceneNodeRenderer.h"
#include "Transformation.h"

#include <iostream>
#include <set>

using namespace turboHiker;

turboHiker::World::World(int nrLanes, double laneWidth, double laneHeight)
    : mWorldBorders(BoundingBox(0, 0, nrLanes * laneWidth, laneHeight))
{
}

void World::update(Updatable::seconds dt)
{

        generateCompetingHikers(dt);

        mSceneGraph.update(dt);

        // Update the center of view so the player is tracked in the middle
        trackPlayer();

        // Now update the render components. Make sure to update it after the Transformation singleton has altered its
        // view (due to trackPlayer).
        mSceneGraph.updateRenderComponents(dt);

        while (!mCommandQueue.isEmpty()) {
                Command command = mCommandQueue.pop();
                onCommand(command, dt);
                mSceneGraph.onCommand(command, dt);
        }

        handleCollisions();

        removeCompetingHikers();
        mSceneGraph.cleanupDeadObjects();
}

void World::renderWorld() { mSceneGraph.render(); }

void turboHiker::World::buildWorld(int nrLanes)
{
        assert(mEntityFactory != nullptr && "Entityfactory not set: no way to create new entities");

        for (int lane = 0; lane < nrLanes + 0; lane++) {
                SceneNode currentLane = mEntityFactory->createLane(
                    BoundingBox(getWorldBorders().getLeft() + getWorldBorders().getWidth() / nrLanes * lane,
                                getWorldBorders().getBottom(), getWorldBorders().getWidth() / nrLanes,
                                getWorldBorders().getHeight()));

                mSceneGraph.addLane(currentLane);
        }

        mSceneGraph.setPlayerHiker(mEntityFactory->createPlayerHiker(0, Vector2d(10, 10)));

        putHikerOnLane(mSceneGraph.getPlayerHiker(), 2);
}

void World::generateCompetingHikers(seconds dt)
{

        double playerSight =
            Transformation::get().getWorldViewCenter().y + Transformation::get().getWorldView().getWorldViewHeight();

        // We want the enemies to spawn on the fly as the player moves

        // TODO calculate chance based on the closeness to the finish
        // The chance of an enemy spawning in a second, on one of the lanes
        // TODO improve this rate to be more consistent
        double spawnRate = 100 * dt.count();
        //        assert(spawnRate >= 0 && spawnRate <= 1);

        bool enemyShouldSpawn = false;
        double randomNumber = Random::get().randomNumber();

        // An enemy should spawn
        if (randomNumber < spawnRate) {
                enemyShouldSpawn = true;
        }

        int previousChosenLane = 0;

        // TODO no enemies are placed on lane 0
        if (enemyShouldSpawn) {

                int chosenLane;

                do {
                        chosenLane = static_cast<int>(
                            std::round(Random::get().randomNumber() * (mSceneGraph.getAmountOfLanes() - 1)));
                } while (chosenLane == previousChosenLane);

                assert(chosenLane >= 0 && chosenLane < mSceneGraph.getAmountOfLanes());

                Vector2d size(10, 10);

                // If true, spawn a static hiker, false: spawn a moving hiker
                bool spawnStatic = static_cast<int>(std::round(Random::get().randomNumber())) == 1;

                double yLocation = playerSight + size.y;

                if (spawnStatic) {
                        Hiker hiker = mEntityFactory->createStaticHiker(yLocation, size);
                        putHikerOnLane(hiker, chosenLane);
                        mSceneGraph.addCompetingHiker(hiker);
                } else {
                        Hiker hiker = mEntityFactory->createMovingHiker(yLocation, size, Vector2d(0, -50));
                        putHikerOnLane(hiker, chosenLane);
                        mSceneGraph.addCompetingHiker(hiker);
                }

                previousChosenLane = chosenLane;
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

bool World::matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
        unsigned int category1 = colliders.first->getCategory();
        unsigned int category2 = colliders.second->getCategory();

        // Make sure first pair entry has category type1 and second has type2
        if (type1 & category1 && type2 & category2) {
                return true;
        } else if (type1 & category2 && type2 & category1) {
                std::swap(colliders.first, colliders.second);
                return true;
        } else {
                return false;
        }
}

void turboHiker::World::handleCollisions()
{
        std::set<SceneNode::Pair> collisionPairs;

        // TODO find collision pairs this->checkSceneCollision(*this, collisionPairs);

        for (const SceneNode::Pair pair : collisionPairs) {
                // TODO react, do something
        }
}

void turboHiker::World::setEntityFactory(std::unique_ptr<EntityFactory> entityFactory)
{
        assert(mEntityFactory == nullptr && "Entity factory can only be set once");
        mEntityFactory = std::move(entityFactory);
}

turboHiker::CommandQueue& turboHiker::World::getCommandQueue() { return mCommandQueue; }
const turboHiker::BoundingBox& turboHiker::World::getWorldBorders() const { return mWorldBorders; }

Hiker& World::getPlayerHiker() const { return mSceneGraph.getPlayerHiker(); }

void World::putHikerOnLane(Hiker& hiker, int laneIndex)
{

        assert(laneIndex < getAmountOfLanes() && laneIndex >= 0);
        SceneNode& lane = mSceneGraph.getLane(laneIndex);
        assert(lane.hasBoundingBox());

        hiker.setLocation(Vector2d(lane.getLocation().x, hiker.getLocation().y));
        hiker.setCurrentLane(laneIndex);
}

unsigned int World::getAmountOfLanes() const { return mSceneGraph.getAmountOfLanes(); }

unsigned int World::getCategory() const { return turboHiker::Category::World; }
