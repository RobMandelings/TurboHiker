//
// Created by RobMa on 23/12/2020.
//

#include "Entity.h"
#include "BoundingBox.h"
#include "Renderer.h"
#include "GameCategory.h"

turboHiker::Entity::Entity(const turboHiker::Vector2d& location, const Vector2d& size,
                           const turboHiker::Vector2d& velocity, const std::string& name)
    : SceneNode(location, size, name), mVelocity(velocity)
{
}

unsigned int turboHiker::Entity::getCategory() const { return GameCategory::GameEntity; }

void turboHiker::Entity::setVelocity(const turboHiker::Vector2d& velocity) { mVelocity = velocity; }

turboHiker::Vector2d turboHiker::Entity::getVelocity() const { return mVelocity; }
void turboHiker::Entity::accelerate(const turboHiker::Vector2d& acceleration) { mVelocity += acceleration; }

void turboHiker::Entity::update(turboHiker::Updatable::seconds dt) { mLocation += mVelocity * dt; }