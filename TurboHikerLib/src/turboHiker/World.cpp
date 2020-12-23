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

turboHiker::World::World(std::unique_ptr<EntityFactory> entityFactory) : mEntityFactory(std::move(entityFactory))
{
        buildWorld();
}

void turboHiker::World::update(Updatable::seconds dt)
{

        for (const std::unique_ptr<Entity>& mainEntity : mMainEntities) {
                mainEntity->update(dt);
        }
        std::cout << "Check me out" << std::endl;
}

void turboHiker::World::draw() const {}

void turboHiker::World::buildWorld()
{
        // Pre-condition
        assert(mMainEntities.empty() && "The world is already built!");

        mMainEntities.push_back(mEntityFactory->createStaticHiker(Vector2d(20, 50)));
}
