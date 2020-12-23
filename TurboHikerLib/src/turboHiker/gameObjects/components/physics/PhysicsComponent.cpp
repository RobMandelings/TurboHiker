//
// Created by Rob Mandelings on 22/12/2020.
//

#include "PhysicsComponent.h"
#include <cassert>

#include "BoundingBox.h"
#include "CollisionComponent.h"
#include "WorldLocation.h"

#include <iostream>

turboHiker::PhysicsComponent::PhysicsComponent(const Vector2d& initialLocation,
                                               std::unique_ptr<CollisionComponent> collisionComponent)
    : mLocation(initialLocation), mCollisionComponent(std::move(collisionComponent))
{
}

void turboHiker::PhysicsComponent::update(turboHiker::Updatable::seconds dt) {}

void turboHiker::PhysicsComponent::handleCollision(const turboHiker::Entity& entity)
{
        if (mCollisionComponent->collidesWith(entity)) {
                mCollisionComponent->handleCollision(entity);
        }
}

void turboHiker::PhysicsComponent::move(const turboHiker::Vector2d& vector2D) { mLocation += vector2D;
}
const turboHiker::Vector2d& turboHiker::PhysicsComponent::getLocation() const { return mLocation; }
void turboHiker::PhysicsComponent::setWorldLocation(const turboHiker::Vector2d& newLocation)
{
        mLocation = newLocation;
}
const turboHiker::BoundingBox& turboHiker::PhysicsComponent::getBoundingBox() const
{
        return mCollisionComponent->getBoundingBox();
}