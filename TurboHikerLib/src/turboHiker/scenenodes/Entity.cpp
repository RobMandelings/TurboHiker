//
// Created by RobMa on 23/12/2020.
//

#include "Entity.h"
#include "BoundingBox.h"
#include "SceneNodeRenderer.h"

turboHiker::Entity::Entity(const turboHiker::Vector2d& initialLocation, const Vector2d& boundingSize,
                           std::unique_ptr<SceneNodeRenderer> renderComponent, const turboHiker::Vector2d& mVelocity,
                           const std::string& name)
    : SceneNode(initialLocation, boundingSize, std::move(renderComponent), name), mVelocity(mVelocity)
{
}

void turboHiker::Entity::setVelocity(const turboHiker::Vector2d& newVelocity) { mVelocity = newVelocity; }

turboHiker::Vector2d turboHiker::Entity::getVelocity() const {
        return mVelocity;
}
void turboHiker::Entity::accelerate(const turboHiker::Vector2d& acceleration) { mVelocity += acceleration; }

void turboHiker::Entity::update(turboHiker::Updatable::seconds dt) { mLocation += mVelocity * dt; }