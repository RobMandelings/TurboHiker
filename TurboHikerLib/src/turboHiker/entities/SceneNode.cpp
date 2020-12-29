//
// Created by RobMa on 19/12/2020.
//

#include "SceneNode.h"

#include <algorithm>
#include <cassert>
#include <set>

#include "BoundingBox.h"
#include "CollisionComponent.h"
#include "RenderComponent.h"

#include "Command.h"

#include "WorldLocation.h"

#include <iostream>
#include <turboHiker/Category.h>
#include <utility>

namespace turboHiker {

SceneNode::SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize,
                     std::unique_ptr<RenderComponent> renderComponent, std::string name)
    : mParent(nullptr), mLocation(initialLocation), mBoundingSize(boundingSize),
      mRenderComponent(std::move(renderComponent)), mName(std::move(name))
{
}

SceneNode::SceneNode() : SceneNode(Vector2d(0, 0), Vector2d(0, 0), nullptr, "SceneNode") {}

void SceneNode::attachChild(SceneNode::SceneNodePtr child)
{
        child->mParent = this;
        onChildAttached(*child);
        mChildren.push_back(std::move(child));
}

void SceneNode::onChildAttached(const SceneNode& child)
{
        // Do nothing by default
}
SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode& child)
{
        auto found =
            std::find_if(mChildren.begin(), mChildren.end(), [&child](SceneNodePtr& p) { return p.get() == &child; });
        assert(found != mChildren.end());

        SceneNodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool SceneNode::hasChildren() { return !mChildren.empty(); }

void SceneNode::update(Updatable::seconds dt)
{
        updateChildren(dt);
        updateCurrent(dt);
}

void SceneNode::updateRenderComponents(Updatable::seconds dt) const
{
        if (mRenderComponent) {
                // Update the render component so it can alter its RenderState / Representation / ...
                // TODO improve to not use the absolute location directly
                // TODO use getWorldLocation() function to get the absolute location
                mRenderComponent->update(dt, getLocation());
        }
        for (const SceneNodePtr& child : mChildren) {
                child->updateRenderComponents(dt);
        }
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
        renderChildren();
        renderCurrent();
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

BoundingBox SceneNode::getBoundingBox() const
{
        assert(hasBoundingBox());
        return BoundingBox(getLocation().x - mBoundingSize.x / 2, getLocation().y - mBoundingSize.y / 2,
                           getLocation().x + mBoundingSize.x / 2, getLocation().y + mBoundingSize.y);
}

bool SceneNode::hasBoundingBox() const { return mBoundingSize.x != 0 && mBoundingSize.y != 0; }

bool SceneNode::collidesWith(const SceneNode& other) const
{
        if (&other != this && hasBoundingBox() && other.hasBoundingBox()) {

                double val = this->getBoundingBox().getRight();
                double val2 = other.getBoundingBox().getLeft();

                // Check if one rectangle is on the left side of the other
                if (this->getBoundingBox().getLeft() > other.getBoundingBox().getRight() ||
                    other.getBoundingBox().getLeft() > this->getBoundingBox().getRight()) {
                        return false;
                }

                if (this->getBoundingBox().getBottom() > other.getBoundingBox().getTop() ||
                    other.getBoundingBox().getBottom() > this->getBoundingBox().getTop()) {
                        return false;
                }

                return true;
        }
        return false;
}

bool SceneNode::collidesWith(const SceneNode& lhs, const SceneNode& rhs) { return lhs.collidesWith(rhs); }

void SceneNode::handleCollisionInternal(const SceneNode& entity)
{
        assert(collidesWith(entity));
        assert(hasBoundingBox());
        // Do nothing by default, needs to be handled by the specific entity
}

void SceneNode::checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs)
{
        checkNodeCollision(sceneGraph, collisionPairs);

        for (const std::unique_ptr<SceneNode>& child : sceneGraph.mChildren) {
                checkSceneCollision(*child, collisionPairs);
        }
}

void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
        if (this != &node && this->collidesWith(node) && !isMarkedForRemoval() && !node.isMarkedForRemoval()) {
                collisionPairs.insert(std::minmax(this, &node));
        }

        for (const std::unique_ptr<SceneNode>& child : mChildren) {
                child->checkNodeCollision(node, collisionPairs);
        }
}

void SceneNode::setBoundingSize(const Vector2d& boundingSize)
{
        assert(boundingSize.x >= 0);
        assert(boundingSize.y >= 0);
        mBoundingSize = boundingSize;
}
void SceneNode::setBoundingWidth(double width) { setBoundingSize(Vector2d(width, mBoundingSize.y)); }
void SceneNode::setBoundingHeight(double height) { setBoundingSize(Vector2d(mBoundingSize.x, height)); }

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
const std::string& SceneNode::getName() const { return mName; }

} // namespace turboHiker