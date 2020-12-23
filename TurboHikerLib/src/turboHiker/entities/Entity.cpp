//
// Created by RobMa on 19/12/2020.
//

#include "Entity.h"

#include <algorithm>
#include <cassert>

#include "CollisionComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"

#include "WorldLocation.h"

#include <iostream>

namespace turboHiker {

Entity::Entity(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> mBoundingBox,
               std::unique_ptr<RenderComponent> renderComponent)
    : mParent(nullptr), mLocation(initialLocation), mBoundingBox(std::move(mBoundingBox)),
      mRenderComponent(std::move(renderComponent))
{
}

Entity::Entity()
    : Entity(Vector2d(0, 0), nullptr, nullptr)
{
}

void Entity::attachChild(Entity::SceneNodePtr child)
{
        child->mParent = this;
        mChildren.push_back(std::move(child));
}
Entity::SceneNodePtr Entity::detachChild(const Entity& gameObject)
{
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&gameObject](SceneNodePtr& p) { return p.get() == &gameObject; });
        assert(found != mChildren.end());

        SceneNodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool Entity::hasChildren() { return !mChildren.empty(); }

void Entity::update(Updatable::seconds dt)
{

        updateCurrent(dt);
        if (mRenderComponent) {
                // Update the render component so it can alter its RenderState / Representation / ...
                // TODO improve to not use the absolute location directly
                // TODO use getWorldLocation() function to get the absolute location
                mRenderComponent->update(dt, getLocation());
        }

        updateChildren(dt);
}

void Entity::updateCurrent(Updatable::seconds dt)
{
        // Do nothing by default
}
void Entity::updateChildren(Updatable::seconds dt)
{
        for (const SceneNodePtr& child : mChildren) {
                child->update(dt);
        }
}

void Entity::render() const
{
        renderCurrent();
        renderChildren();
}

void Entity::renderCurrent() const
{
        if (mRenderComponent) {
                mRenderComponent->render();
        }
}

void Entity::renderChildren() const
{
        for (const SceneNodePtr& gameObjectPtr : mChildren) {
                gameObjectPtr->render();
        }
}

void Entity::handleCollision(const Entity& entity)
{
        if (collidesWith(entity)) {
                handleCollisionInternal(entity);
        }
}
bool Entity::hasBoundingBox() const { return mBoundingBox != nullptr; }
bool Entity::collidesWith(const Entity& entity) const
{
        if (&entity != this && hasBoundingBox() && entity.hasBoundingBox()) {
                // TODO implement collision detection with other entity
        } else {
                return false;
        }
        return false;
}

void Entity::handleCollisionInternal(const Entity& entity)
{
        assert(collidesWith(entity));
        assert(hasBoundingBox());
        // Do nothing by default, needs to be handled by the specific entity
}

const Vector2d& Entity::getLocation() const { return mLocation; }
void Entity::setLocation(const Vector2d& newLocation) { mLocation = newLocation; }
} // namespace turboHiker