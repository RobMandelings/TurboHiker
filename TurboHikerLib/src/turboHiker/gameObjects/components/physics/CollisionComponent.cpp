//
// Created by RobMa on 23/12/2020.
//

#include "CollisionComponent.h"

/** Do nothing by default */
void turboHiker::CollisionComponent::handleCollision(const turboHiker::Entity& entity) {}

const turboHiker::BoundingBox& turboHiker::CollisionComponent::getBoundingBox() const { return mBoundingBox; }
