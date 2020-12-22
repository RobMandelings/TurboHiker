//
// Created by Rob Mandelings on 22/12/2020.
//

#include "PhysicsComponent.h"
#include <cassert>

#include "BoundingBox.h"
#include "WorldPosition.h"

turboHiker::PhysicsComponent::PhysicsComponent(const WorldPosition& worldPosition, const BoundingBox& boundingBox)
    : mWorldPosition(worldPosition), mBoundingBox(boundingBox)
{
}

void turboHiker::PhysicsComponent::update(turboHiker::Updatable::seconds dt) { }

void turboHiker::PhysicsComponent::move(const turboHiker::Vector2d& vector2D) { mWorldPosition.move(vector2D); }
const turboHiker::WorldPosition& turboHiker::PhysicsComponent::getWorldPosition() const { return mWorldPosition; }
void turboHiker::PhysicsComponent::setWorldLocation(const turboHiker::Vector2d& newPosition) {
        mWorldPosition.setPosition(newPosition);
}
const turboHiker::BoundingBox& turboHiker::PhysicsComponent::getBoundingBox() const { return mBoundingBox; }