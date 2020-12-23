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

turboHiker::World::World() : mEntityFactory(nullptr)
{}

void turboHiker::World::update(Updatable::seconds dt)
{

        for (const std::unique_ptr<Entity>& mainEntity : mMainEntities) {
                mainEntity->update(dt);
        }
        std::cout << "Check me out" << std::endl;
}

void turboHiker::World::render() const {
        for (const std::unique_ptr<Entity>& mainEntity : mMainEntities) {
                mainEntity->render();
        }
}

void turboHiker::World::buildWorld()
{
        assert(mEntityFactory != nullptr && "Entityfactory not set: no way to create new entities");
        // Pre-condition
        assert(mMainEntities.empty() && "The world is already built!");

        mMainEntities.push_back(mEntityFactory->createTestCircle(Vector2d(20, 50), Vector2d(5, 10)));
        mMainEntities.push_back(mEntityFactory->createTestCircle(Vector2d(50, 50), Vector2d(2, -5)));
}

void turboHiker::World::setEntityFactory(std::unique_ptr<EntityFactory> entityFactory) {
        mEntityFactory = std::move(entityFactory);
}