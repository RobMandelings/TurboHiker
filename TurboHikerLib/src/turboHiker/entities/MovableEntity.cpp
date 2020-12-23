//
// Created by RobMa on 23/12/2020.
//

#include "MovableEntity.h"
#include "BoundingBox.h"
#include "RenderComponent.h"

turboHiker::MovableEntity::MovableEntity(const turboHiker::Vector2d& initialLocation,
                                         std::unique_ptr<BoundingBox> mBoundingBox,
                                         std::unique_ptr<RenderComponent> renderComponent,
                                         const turboHiker::Vector2d& mVelocity)
    : SceneNode(initialLocation, std::move(mBoundingBox), std::move(renderComponent)), mVelocity(mVelocity)
{
}

void turboHiker::MovableEntity::setVelocity(const turboHiker::Vector2d& newVelocity) {
        mVelocity = newVelocity;
}
void turboHiker::MovableEntity::accelerate(const turboHiker::Vector2d& acceleration) {
        mVelocity += acceleration;
}

void turboHiker::MovableEntity::updateCurrent(turboHiker::Updatable::seconds dt) { mLocation += mVelocity * dt; }