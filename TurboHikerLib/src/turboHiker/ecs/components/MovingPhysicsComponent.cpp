//
// Created by RobMa on 22/12/2020.
//

#include "MovingPhysicsComponent.h"
#include "Vector2d.h"

#include "WorldPosition.h"

turboHiker::MovingPhysicsComponent::MovingPhysicsComponent(std::unique_ptr<WorldPosition> position,
                                                           std::unique_ptr<BoundingBox> boundingBox,
                                                           std::unique_ptr<Vector2d> velocity)
    : PhysicsComponent(std::move(position), std::move(boundingBox)), mVelocity(std::move(velocity))
{
}

void turboHiker::MovingPhysicsComponent::update(turboHiker::Updatable::seconds dt)
{
        PhysicsComponent::update(dt);
        move(*mVelocity * dt);
}

void turboHiker::MovingPhysicsComponent::setVelocity(const turboHiker::Vector2d& newVelocity) {
        *mVelocity = newVelocity;
}
void turboHiker::MovingPhysicsComponent::setVelocityX(double newVelocityX) {
        mVelocity->x = newVelocityX;
}
void turboHiker::MovingPhysicsComponent::setVelocityY(double newVelocityY) {
        mVelocity->y = newVelocityY;
}
const turboHiker::Vector2d& turboHiker::MovingPhysicsComponent::getVelocity() const { return *mVelocity; }