//
// Created by RobMa on 23/12/2020.
//

#include "Entity.h"
#include "BoundingBox.h"
#include "RenderComponent.h"

turboHiker::Entity::Entity(const turboHiker::Vector2d& initialLocation, const Vector2d& boundingSize,
                           std::unique_ptr<RenderComponent> renderComponent, const turboHiker::Vector2d& mVelocity)
    : SceneNode(initialLocation, boundingSize, std::move(renderComponent)), mVelocity(mVelocity)
{
}

void turboHiker::Entity::setVelocity(const turboHiker::Vector2d& newVelocity) { mVelocity = newVelocity; }
void turboHiker::Entity::accelerate(const turboHiker::Vector2d& acceleration) { mVelocity += acceleration; }

void turboHiker::Entity::updateCurrent(turboHiker::Updatable::seconds dt) { mLocation += mVelocity * dt; }