//
// Created by RobMa on 23/12/2020.
//

#include "CollisionComponent.h"

turboHiker::CollisionComponent::CollisionComponent(const turboHiker::BoundingBox& boundingBox)
    : mBoundingBox(boundingBox)
{
}

bool turboHiker::CollisionComponent::collidesWith(const turboHiker::Entity& entity) {
        // Needs to be implemented
        return false;
}

/** Do nothing by default */
void turboHiker::CollisionComponent::handleCollision(const turboHiker::Entity& entity) {}

const turboHiker::BoundingBox& turboHiker::CollisionComponent::getBoundingBox() const { return mBoundingBox; }