//
// Created by Rob Mandelings on 31/12/2020.
//

#include "SceneGraph.h"

#include "Hiker.h"
#include "SceneNode.h"
#include "SceneNodeRenderer.h"
#include <cassert>

using namespace turboHiker;

// TODO is there a way that all fields present in this sceneGraph is updated?
void turboHiker::SceneGraph::update(turboHiker::Updatable::seconds dt)
{

        for (const std::reference_wrapper<SceneNode>& child : getChildren()) {
                child.get().update(dt);
        }

        // The lanes don't need to be updated at all
}

void SceneGraph::updateRenderComponents(Updatable::seconds dt)
{
        for (const std::reference_wrapper<SceneNode>& child : getChildren()) {
                child.get().updateRenderComponent(dt);
        }
}

void turboHiker::SceneGraph::render() const
{
        for (const std::reference_wrapper<SceneNode>& child : getChildren()) {
                child.get().render();
        }
}

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

        assert(playerHiker.isPlayerControlled());
        mPlayerHiker = std::make_unique<Hiker>(playerHiker);
}
void SceneGraph::addLane(const SceneNode& lane) { mLanes.push_back(std::make_unique<SceneNode>(lane)); }

std::vector<std::reference_wrapper<SceneNode>> SceneGraph::getChildren() const
{
        assert(mPlayerHiker && "Player is not initialized");

        std::vector<std::reference_wrapper<SceneNode>> children;

        children.reserve(mSceneNodes.size());
        for (const std::unique_ptr<SceneNode>& currentSceneNode : mSceneNodes) {
                children.emplace_back(*currentSceneNode);
        }

        children.reserve(mCompetingHikers.size());
        for (const std::unique_ptr<Hiker>& currentCompetingHiker : mCompetingHikers) {
                children.emplace_back(*currentCompetingHiker);
        }

        children.reserve(mLanes.size());
        for (const std::unique_ptr<SceneNode>& currentLane : mLanes) {
                children.emplace_back(*currentLane);
        }

        children.emplace_back(*mPlayerHiker);

        return children;
}

void SceneGraph::onCommand(const Command& command, std::chrono::duration<double> dt)
{
        for (const std::reference_wrapper<SceneNode>& child : getChildren()) {
                child.get().onCommand(command, dt);
        }
}
