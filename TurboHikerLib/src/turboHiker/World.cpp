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
}

void turboHiker::World::render() const { mSceneGraph.render(); }

void turboHiker::World::buildWorld()
{
        assert(mEntityFactory != nullptr && "Entityfactory not set: no way to create new entities");

        //mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(0, 49), Vector2d(0, 0)));
        // mSceneGraph.attachChild(mEntityFactory->createTestCircle(Vector2d(50, 50), Vector2d(0, 0)));

        mSceneGraph.attachChild(mEntityFactory->createHiker(Vector2d(20, 0), Vector2d(0, 0), true));
}

void turboHiker::World::setEntityFactory(std::unique_ptr<EntityFactory> entityFactory)
{
        assert(mEntityFactory == nullptr && "Entity factory can only be set once");
        mEntityFactory = std::move(entityFactory);
}

turboHiker::CommandQueue& turboHiker::World::getCommandQueue() { return mCommandQueue; }
const turboHiker::BoundingBox& turboHiker::World::getWorldBorders() const { return mWorldBorders; }
