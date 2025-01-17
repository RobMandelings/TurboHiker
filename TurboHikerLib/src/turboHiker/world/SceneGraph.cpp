//
// Created by Rob Mandelings on 31/12/2020.
//

#include "SceneGraph.h"

#include "BoundingBox.h"
#include "Finish.h"
#include "Hiker.h"
#include "PlayerHiker.h"
#include "Renderer.h"
#include "RunningHiker.h"
#include "SceneNode.h"
#include "StaticHiker.h"
#include <algorithm>
#include <cassert>

using namespace turboHiker;

void SceneGraph::clear()
{
        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->markForRemoval();
        }
        cleanupDeadObjects();
}

// TODO is there a way that all fields present in this sceneGraph is updated?
void turboHiker::SceneGraph::update(turboHiker::Updatable::seconds dt)
{

        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                if (!sceneNode->isMarkedForRemoval()) {
                        sceneNode->update(dt);
                }
        }

        // The lanes don't need to be updated at all
}

void SceneGraph::updateRenderComponents(Updatable::seconds dt)
{
        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                if (!sceneNode->isMarkedForRemoval()) {
                        sceneNode->updateRenderComponent(dt);
                }
        }
}

void turboHiker::SceneGraph::render() const
{
        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                if (!sceneNode->isMarkedForRemoval()) {
                        sceneNode->render();
                }
        }
}

void SceneGraph::cleanupDeadObjects()
{

        auto sceneNodeIt = mSceneNodes.begin();
        while (sceneNodeIt != mSceneNodes.end()) {

                if ((*sceneNodeIt)->isMarkedForRemoval()) {
                        sceneNodeIt = mSceneNodes.erase(sceneNodeIt);
                } else {
                        sceneNodeIt++;
                }
        }

        auto lanesIt = mLanes.begin();

        while (lanesIt != mLanes.end()) {

                if (!(*lanesIt).lock()) {
                        lanesIt = mLanes.erase(lanesIt);
                } else {
                        lanesIt++;
                }
        }

        auto competingHikersIt = mCompetingHikers.begin();

        while (competingHikersIt != mCompetingHikers.end()) {

                if ((*competingHikersIt).lock() == nullptr) {
                        competingHikersIt = mCompetingHikers.erase(competingHikersIt);
                } else {
                        competingHikersIt++;
                }
        }

        if (!mPlayerHiker.lock()) {
                mPlayerHiker.reset();
        }
}

bool SceneGraph::spaceOccupiedBy(const BoundingBox& boundingBox, const GameCategory& category)
{

        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                if (sceneNode->getCategory() & category) {
                        if (sceneNode->collidesWith(boundingBox)) {
                                return true;
                        }
                }
        }
        return false;
}

std::set<turboHiker::SceneGraph::SceneNodePair> SceneGraph::findCollisionPairs() const
{

        std::set<SceneNodePair> collisionPairs;

        for (const std::shared_ptr<SceneNode>& sceneNode1 : mSceneNodes) {

                for (const std::shared_ptr<SceneNode>& sceneNode2 : mSceneNodes) {

                        // Skip if they are the same
                        if (&sceneNode1 == &sceneNode2)
                                continue;

                        if (sceneNode1->collidesWith(*sceneNode2)) {

                                collisionPairs.insert(std::minmax(sceneNode1, sceneNode2));
                        }
                }
        }

        return collisionPairs;
}

turboHiker::PlayerHiker& turboHiker::SceneGraph::getPlayerHiker() const
{
        assert(mPlayerHiker.lock() && "Player not defined");
        return *mPlayerHiker.lock();
}

unsigned int SceneGraph::getAmountOfSceneNodes() const { return mSceneNodes.size(); }
unsigned int SceneGraph::getAmountOfLanes() const { return mLanes.size(); }
unsigned int SceneGraph::getAmountOfCompetingHikers() const { return mCompetingHikers.size(); }
SceneNode& SceneGraph::getSceneNode(unsigned int index) const
{
        assert(index < mSceneNodes.size());
        assert(mSceneNodes.at(index));
        return *mSceneNodes.at(index);
}
Hiker& SceneGraph::getCompetingHiker(unsigned int index) const
{
        assert(index < mCompetingHikers.size());
        assert(mCompetingHikers.at(index).lock());
        return *mCompetingHikers.at(index).lock();
}
SceneNode& SceneGraph::getLane(unsigned int index) const
{
        assert(index < mLanes.size());
        assert(mLanes.at(index).lock());
        return *mLanes.at(index).lock();
}

Finish& SceneGraph::getFinish() const { return *mFinish.lock(); }

void SceneGraph::addSceneNode(const SceneNode& sceneNode)
{
        mSceneNodes.push_back(std::make_shared<SceneNode>(sceneNode));
}

void SceneGraph::addStaticHiker(const StaticHiker& competingHiker)
{
        std::shared_ptr<StaticHiker> staticHikerPtr = std::make_shared<StaticHiker>(competingHiker);
        mSceneNodes.push_back(staticHikerPtr);
        mCompetingHikers.push_back(staticHikerPtr);
}

void SceneGraph::addRunningHiker(const RunningHiker& runningHiker)
{
        std::shared_ptr<RunningHiker> runningHikerPtr = std::make_shared<RunningHiker>(runningHiker);
        mSceneNodes.push_back(runningHikerPtr);
        mCompetingHikers.push_back(runningHikerPtr);
}

void SceneGraph::setPlayerHiker(const PlayerHiker& playerHiker)
{
        std::shared_ptr<PlayerHiker> playerHikerPtr = std::make_shared<PlayerHiker>(playerHiker);
        mSceneNodes.push_back(playerHikerPtr);
        mPlayerHiker = playerHikerPtr;
}
void SceneGraph::addLane(const SceneNode& lane)
{
        std::shared_ptr<SceneNode> lanePtr = std::make_shared<SceneNode>(lane);
        mSceneNodes.push_back(lanePtr);
        mLanes.push_back(lanePtr);
}

void SceneGraph::setFinish(const Finish& finish)
{
        std::shared_ptr<Finish> finishPtr = std::make_shared<Finish>(finish);
        mSceneNodes.push_back(finishPtr);
        mFinish = finishPtr;
}

void SceneGraph::onCommand(const Command& command, std::chrono::duration<double> dt)
{

        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->onCommand(command, dt);
        }
}