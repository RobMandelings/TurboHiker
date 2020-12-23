//
// Created by RobMa on 22/12/2020.
//

#include "MovingPhysicsComponent.h"
#include <iostream>

#include "BoundingBox.h"
#include "CollisionComponent.h"
#include "Vector2d.h"
#include "WorldLocation.h"

turboHiker::MovingPhysicsComponent::MovingPhysicsComponent(const Vector2d& initialLocation,
                                                           std::unique_ptr<CollisionComponent> collisionComponent,
                                                           const Vector2d& initialVelocity)
    : PhysicsComponent(initialLocation, std::move(collisionComponent)), mVelocity(initialVelocity)
{
}

void turboHiker::MovingPhysicsComponent::update(turboHiker::Updatable::seconds dt)
{
        PhysicsComponent::update(dt);
        move(mVelocity * dt);
        std::cout << mVelocity << std::endl;
        std::cout << getLocation() << std::endl;
}

void turboHiker::MovingPhysicsComponent::setVelocity(const turboHiker::Vector2d& newVelocity)
{
        mVelocity = newVelocity;
}
void turboHiker::MovingPhysicsComponent::setVelocityX(double newVelocityX) { mVelocity.x = newVelocityX; }
void turboHiker::MovingPhysicsComponent::setVelocityY(double newVelocityY) { mVelocity.y = newVelocityY; }
const turboHiker::Vector2d& turboHiker::MovingPhysicsComponent::getVelocity() const { return mVelocity; }