//
// Created by RobMa on 22/12/2020.
//

#include "MovingPhysicsComponent.h"

#include "BoundingBox.h"
#include "Vector2d.h"
#include "WorldLocation.h"

turboHiker::MovingPhysicsComponent::MovingPhysicsComponent(const WorldLocation& initialWorldPosition,
                                                           const BoundingBox& initialBoundingBox,
                                                           const Vector2d& initialVelocity)
    : PhysicsComponent(initialWorldPosition, initialBoundingBox), mVelocity(initialVelocity)
{
}

void turboHiker::MovingPhysicsComponent::update(turboHiker::Updatable::seconds dt)
{
        PhysicsComponent::update(dt);
        move(mVelocity * dt);
}

void turboHiker::MovingPhysicsComponent::setVelocity(const turboHiker::Vector2d& newVelocity) {
        mVelocity = newVelocity;
}
void turboHiker::MovingPhysicsComponent::setVelocityX(double newVelocityX) {
        mVelocity.x = newVelocityX;
}
void turboHiker::MovingPhysicsComponent::setVelocityY(double newVelocityY) {
        mVelocity.y = newVelocityY;
}
const turboHiker::Vector2d& turboHiker::MovingPhysicsComponent::getVelocity() const { return mVelocity; }