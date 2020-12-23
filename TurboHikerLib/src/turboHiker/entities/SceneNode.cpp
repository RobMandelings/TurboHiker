//
// Created by RobMa on 19/12/2020.
//

#include "SceneNode.h"

#include <algorithm>
#include <cassert>

#include "CollisionComponent.h"
#include "RenderComponent.h"
#include "BoundingBox.h"

#include "Command.h"

#include "WorldLocation.h"

#include <iostream>
#include <turboHiker/Category.h>

namespace turboHiker {

SceneNode::SceneNode(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> mBoundingBox,
                     std::unique_ptr<RenderComponent> renderComponent)
    : mParent(nullptr), mLocation(initialLocation), mBoundingBox(std::move(mBoundingBox)),
      mRenderComponent(std::move(renderComponent))
{
}

SceneNode::SceneNode() : SceneNode(Vector2d(0, 0), nullptr, nullptr) {}

void SceneNode::attachChild(SceneNode::SceneNodePtr child)
{
        child->mParent = this;
        mChildren.push_back(std::move(child));
}
SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode& gameObject)
{
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&gameObject](SceneNodePtr& p) { return p.get() == &gameObject; });
        assert(found != mChildren.end());

        SceneNodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool SceneNode::hasChildren() { return !mChildren.empty(); }

void SceneNode::update(Updatable::seconds dt)
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

void SceneNode::updateCurrent(Updatable::seconds dt)
{
        // Do nothing by default
}
void SceneNode::updateChildren(Updatable::seconds dt)
{
        for (const SceneNodePtr& child : mChildren) {
                child->update(dt);
        }
}

void SceneNode::render() const
{
        renderCurrent();
        renderChildren();
}

void SceneNode::renderCurrent() const
{
        if (mRenderComponent) {
                mRenderComponent->render();
        }
}

void SceneNode::renderChildren() const
{
        for (const SceneNodePtr& gameObjectPtr : mChildren) {
                gameObjectPtr->render();
        }
}

void SceneNode::handleCollision(const SceneNode& entity)
{
        if (collidesWith(entity)) {
                handleCollisionInternal(entity);
        }
}

unsigned int SceneNode::getCategory() const { return Category::Scene; }
bool SceneNode::hasBoundingBox() const { return mBoundingBox != nullptr; }

bool SceneNode::collidesWith(const SceneNode& entity) const
{
        if (&entity != this && hasBoundingBox() && entity.hasBoundingBox()) {
                // TODO implement collision detection with other entity
        } else {
                return false;
        }
        return false;
}

void SceneNode::handleCollisionInternal(const SceneNode& entity)
{
        assert(collidesWith(entity));
        assert(hasBoundingBox());
        // Do nothing by default, needs to be handled by the specific entity
}

void SceneNode::onCommand(const Command& command, seconds dt)
{
        // Command current node, if category matches
        if (command.category & getCategory())
                command.action(*this, dt);

        // Command children
        for (std::unique_ptr<SceneNode>& child : mChildren) {
                child->onCommand(command, dt);
        }
}

const Vector2d& SceneNode::getLocation() const { return mLocation; }
void SceneNode::setLocation(const Vector2d& newLocation) { mLocation = newLocation; }
} // namespace turboHiker