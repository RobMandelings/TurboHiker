//
// Created by Rob Mandelings on 22/12/2020.
//

#include "PhysicsSystem.h"
#include <cassert>

turboHiker::PhysicsSystem::PhysicsSystem(std::shared_ptr<WorldPosition> position, std::shared_ptr<Velocity> velocity,
                                         std::shared_ptr<BoundingBox> boundingBox)
    : mWorldPosition(std::move(position)), mVelocity(std::move(velocity)), mBoundingBox(std::move(boundingBox))
{
        assert(mWorldPosition != nullptr);
}

void turboHiker::PhysicsSystem::update(turboHiker::Updatable::seconds dt)
{
        move(mWorldPosition * )
}

void turboHiker::PhysicsSystem::move(const turboHiker::Vector2d& vector2D) {

}
