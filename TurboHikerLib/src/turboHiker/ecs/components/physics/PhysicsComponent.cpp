//
// Created by Rob Mandelings on 22/12/2020.
//

#include "PhysicsComponent.h"
#include <cassert>

#include "BoundingBox.h"
#include "WorldLocation.h"

turboHiker::PhysicsComponent::PhysicsComponent(const WorldLocation& worldPosition, const BoundingBox& boundingBox)
    : mWorldLocation(worldPosition), mBoundingBox(boundingBox)
{
}

void turboHiker::PhysicsComponent::update(turboHiker::Updatable::seconds dt) { }

void turboHiker::PhysicsComponent::move(const turboHiker::Vector2d& vector2D) { mWorldLocation.move(vector2D); }
const turboHiker::WorldLocation& turboHiker::PhysicsComponent::getWorldLocation() const { return mWorldLocation; }
void turboHiker::PhysicsComponent::setWorldLocation(const turboHiker::Vector2d& newLocation) {
        mWorldLocation.setPosition(newLocation);
}
const turboHiker::BoundingBox& turboHiker::PhysicsComponent::getBoundingBox() const { return mBoundingBox; }