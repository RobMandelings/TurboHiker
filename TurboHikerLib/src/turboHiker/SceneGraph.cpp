//
// Created by Rob Mandelings on 31/12/2020.
//

#include "SceneGraph.h"

#include "Hiker.h"
#include "SceneNode.h"
#include "RenderComponent.h"
#include <cassert>

using namespace turboHiker;

// TODO is there a way that all fields present in this sceneGraph is updated?
void turboHiker::SceneGraph::update(turboHiker::Updatable::seconds dt)
{
        // Update all General SceneNodes
        for (const std::unique_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->update(dt);
        }

        // Update all (other) hikers
        for (const std::unique_ptr<Hiker>& competingHiker : mCompetingHikers) {
                competingHiker->update(dt);
        }

        // Update the player hiker
        mPlayerHiker->update(dt);

        // The lanes don't need to be updated at all
}

void SceneGraph::updateRenderComponents(Updatable::seconds dt)
{
        // Update all General SceneNodes
        for (const std::unique_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->updateRenderComponent(dt);
        }

        // Update all (other) hikers
        for (const std::unique_ptr<Hiker>& competingHiker : mCompetingHikers) {
                competingHiker->updateRenderComponent(dt);
        }

        // Update the player hiker
        mPlayerHiker->updateRenderComponent(dt);

        // The lanes don't need to be updated at all
}

void turboHiker::SceneGraph::render() const
{

        // Render the lanes (background basically)
        for (const std::unique_ptr<SceneNode>& lane : mLanes) {
                lane->render();
        }

        // Render all general SceneNodes
        for (const std::unique_ptr<SceneNode>& sceneNode : mSceneNodes) {
                sceneNode->render();
        }

        // Render all competing hikers
        for (const std::unique_ptr<Hiker>& competingHiker : mCompetingHikers) {
                competingHiker->render();
        }

        // Finally render the player hiker
        mPlayerHiker->render();
}

void SceneGraph::onCommand() {}

turboHiker::Hiker& turboHiker::SceneGraph::getPlayerHiker() const
{
        assert(mPlayerHiker != nullptr && "Player not defined");
        return *mPlayerHiker;
}

const std::vector<std::unique_ptr<SceneNode>>& turboHiker::SceneGraph::getSceneNodes() const { return mSceneNodes; }

const std::vector<std::unique_ptr<Hiker>>& turboHiker::SceneGraph::getCompetingHikers() const
{
        return mCompetingHikers;
}

const std::vector<std::unique_ptr<SceneNode>>& SceneGraph::getLanes() const { return mLanes; }

void SceneGraph::addSceneNode(const SceneNode& sceneNode)
{
        mSceneNodes.push_back(std::make_unique<SceneNode>(sceneNode));
}

void SceneGraph::addCompetingHiker(const Hiker& competingHiker)
{
        mCompetingHikers.push_back(std::make_unique<Hiker>(competingHiker));
}
void SceneGraph::setPlayerHiker(const Hiker& playerHiker) {

        mPlayerHiker = std::make_unique<Hiker>(playerHiker);
}
void SceneGraph::addLane(const SceneNode& lane) { mLanes.push_back(std::make_unique<SceneNode>(lane)); }
