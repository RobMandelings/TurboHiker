//
// Created by RobMa on 19/12/2020.
//

#include "World.h"
#include <cassert>

#include "CollisionComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"

#include <iostream>
#include <set>

using namespace turboHiker;

turboHiker::World::World(const BoundingBox& worldBorders)
    : mSceneGraph(SceneNode()), mEntityFactory(nullptr), mWorldBorders(worldBorders)
{
}

void turboHiker::World::update(Updatable::seconds dt)
{
        mSceneGraph.update(dt);
        while (!mCommandQueue.isEmpty()) {
                mSceneGraph.onCommand(mCommandQueue.pop(), dt);
        }

        handleCollisions();
}

void turboHiker::World::render() const { mSceneGraph.render(); }

void turboHiker::World::buildWorld()
{
        assert(mEntityFactory != nullptr && "Entityfactory not set: no way to create new entities");

        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(0, 49), Vector2d(0, 0)));
        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(50, 50), Vector2d(0, 0)));

        mSceneGraph.attachChild(mEntityFactory->createBackgroundRectangle(getWorldBorders()));

        mSceneGraph.attachChild(mEntityFactory->createHiker(Vector2d(getWorldBorders().getWidth() / 2, 0),
                                                            Vector2d(10, 10), Vector2d(0, 0), true));

        mSceneGraph.attachChild(mEntityFactory->createHiker(Vector2d(getWorldBorders().getWidth() / 2, 0),
                                                            Vector2d(7, 7), Vector2d(0, 0), false));
        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(28, 28), Vector2d(0, 0)));
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
        mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);

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
