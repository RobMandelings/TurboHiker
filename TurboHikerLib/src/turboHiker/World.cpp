//
// Created by RobMa on 19/12/2020.
//

#include "World.h"
#include <cassert>

#include "CollisionComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "Transformation.h"

#include <iostream>
#include <set>

using namespace turboHiker;

turboHiker::World::World(int nrLanes, double laneWidth, double laneHeight,
                         std::unique_ptr<turboHiker::EntityFactory> entityFactory)
    : mPlayerHiker(nullptr), mWorldBorders(BoundingBox(0, 0, nrLanes * laneWidth, laneHeight)),
      mEntityFactory(std::move(entityFactory))
{
}

void World::updateCurrent(Updatable::seconds dt)
{
        // Update the center of view so the player is tracked in the middle
        trackPlayer();
        // Now update the render components. Make sure to update it after the Transformation singleton has altered its
        // view (due to trackPlayer).
        updateRenderComponents(dt);
        while (!mCommandQueue.isEmpty()) {
                onCommand(mCommandQueue.pop(), dt);
        }

        handleCollisions();
}

void turboHiker::World::buildWorld(int nrLanes)
{
        assert(mEntityFactory != nullptr && "Entityfactory not set: no way to create new entities");

        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(0, 49), Vector2d(0, 0)));
        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(50, 50), Vector2d(0, 0)));

        for (int lane = 0; lane < nrLanes + 0; lane++) {
                attachChild(mEntityFactory->createLane(
                    BoundingBox(getWorldBorders().getLeft() + getWorldBorders().getWidth() / nrLanes * lane, getWorldBorders().getBottom(),
                                getWorldBorders().getWidth() / nrLanes * (lane + 1), getWorldBorders().getHeight())));
        }

        attachChild(mEntityFactory->createHiker(Vector2d(getWorldBorders().getWidth() / 2, 0), Vector2d(7, 7),
                                                Vector2d(0, 0), false));

        std::unique_ptr<Hiker> playerHiker = mEntityFactory->createHiker(Vector2d(getWorldBorders().getWidth() / 2, 0),
                                                                         Vector2d(10, 10), Vector2d(0, 0), true);
        mPlayerHiker = playerHiker.get();
        attachChild(std::move(playerHiker));
        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(28, 28), Vector2d(0, 0)));
}

void World::trackPlayer() const
{
        assert(mPlayerHiker != nullptr);
        Transformation::get().setWorldViewCenter(mPlayerHiker->getLocation());
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
        this->checkSceneCollision(*this, collisionPairs);

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

void World::putHikerOnLane(Hiker& hiker, int laneIndex)
{

        SceneNode& lane = *mLanes.at(laneIndex);
        assert(lane.hasBoundingBox());

        hiker.setLocation(
            Vector2d(lane.getBoundingBox().getLeft() + lane.getBoundingBox().getWidth() / 2, hiker.getLocation().y));
}

int World::getAmountOfLanes() const { return mLanes.size(); }
