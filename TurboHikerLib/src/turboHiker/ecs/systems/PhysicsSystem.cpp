//
// Created by Rob Mandelings on 22/12/2020.
//

#include "PhysicsSystem.h"
#include <cassert>

#include "BoundingBox.h"
#include "WorldPosition.h"

turboHiker::PhysicsSystem::PhysicsSystem(std::unique_ptr<WorldPosition> position, std::unique_ptr<Vector2d> velocity,
                                         std::unique_ptr<BoundingBox> boundingBox)
    : mWorldPosition(std::move(position)), mVelocity(std::move(velocity)), mBoundingBox(std::move(boundingBox))
{
        assert(mWorldPosition != nullptr);
}

void turboHiker::PhysicsSystem::update(turboHiker::Updatable::seconds dt) { move(*mVelocity * dt); }

void turboHiker::PhysicsSystem::move(const turboHiker::Vector2d& vector2D) { mWorldPosition->move(vector2D); }
const turboHiker::WorldPosition& turboHiker::PhysicsSystem::getWorldPosition() const { return *mWorldPosition; }
void turboHiker::PhysicsSystem::setWorldPosition(const turboHiker::Vector2d& newPosition) {
        mWorldPosition->get
}
const turboHiker::BoundingBox& turboHiker::PhysicsSystem::getBoundingBox() const { return *mBoundingBox; }