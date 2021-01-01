//
// Created by Rob Mandelings on 31/12/2020.
//

#include "SceneGraph.h"

#include "BoundingBox.h"
#include "Hiker.h"
#include "SceneNode.h"
#include "SceneNodeRenderer.h"
#include <cassert>

using namespace turboHiker;

// TODO is there a way that all fields present in this sceneGraph is updated?
void turboHiker::SceneGraph::update(turboHiker::Updatable::seconds dt)
{

        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->update(dt);
        }

        // The lanes don't need to be updated at all
}

void SceneGraph::updateRenderComponents(Updatable::seconds dt)
{
        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->updateRenderComponent(dt);
        }
}

void turboHiker::SceneGraph::render() const
{
        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->render();
        }
}

void SceneGraph::cleanupDeadObjects()
{

        auto sceneNodeIt = mSceneNodes.begin();
        while (sceneNodeIt != mSceneNodes.end()) {

                if ((*sceneNodeIt)->isMarkedForRemoval()) {
                        std::cout << "Marked" << std::endl;
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

turboHiker::Hiker& turboHiker::SceneGraph::getPlayerHiker() const
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
void SceneGraph::addSceneNode(const SceneNode& sceneNode)
{
        mSceneNodes.push_back(std::make_shared<SceneNode>(sceneNode));
}

void SceneGraph::addCompetingHiker(const Hiker& competingHiker)
{
        std::shared_ptr<Hiker> competingHikerPtr = std::make_shared<Hiker>(competingHiker);
        mSceneNodes.push_back(competingHikerPtr);
        mCompetingHikers.push_back(competingHikerPtr);
}
void SceneGraph::setPlayerHiker(const Hiker& playerHiker)
{
        assert(playerHiker.isPlayerControlled());
        std::shared_ptr<Hiker> playerHikerPtr = std::make_shared<Hiker>(playerHiker);
        mSceneNodes.push_back(playerHikerPtr);
        mPlayerHiker = playerHikerPtr;
}
void SceneGraph::addLane(const SceneNode& lane)
{
        assert(lane.getBoundingBox().getWidth() > 0 && lane.getBoundingBox().getHeight() > 0);
        std::shared_ptr<SceneNode> lanePtr = std::make_shared<SceneNode>(lane);
        mSceneNodes.push_back(lanePtr);
        mLanes.push_back(lanePtr);
}

void SceneGraph::onCommand(const Command& command, std::chrono::duration<double> dt)
{

        for (const std::shared_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->onCommand(command, dt);
        }
}