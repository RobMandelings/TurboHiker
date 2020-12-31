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

using namespace turboHiker;

SceneNode::SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize,
                     std::unique_ptr<RenderComponent> renderComponent, std::string name)
    : mLocation(initialLocation), mBoundingSize(boundingSize), mRenderComponent(std::move(renderComponent)),
      mName(std::move(name))
{
}

// TODO remove as well
SceneNode::SceneNode() : SceneNode(Vector2d(0, 0), Vector2d(0, 0), nullptr, "World") {}

SceneNode::SceneNode(const SceneNode& other) : mBoundingSize(other.mBoundingSize), mLocation(other.mLocation)
{
        mRenderComponent = std::move(other.mRenderComponent->clone());
}

void SceneNode::update(Updatable::seconds dt)
{
        // Do nothing by default
}

void turboHiker::SceneNode::updateRenderComponent(Updatable::seconds dt) const
{
        if (mRenderComponent) {
                mRenderComponent->update(dt, getLocation());
        }
}

void turboHiker::SceneNode::render() const
{
        if (mRenderComponent) {
                mRenderComponent->render();
        }
}

unsigned int turboHiker::SceneNode::getCategory() const { return Category::Scene; }

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

void SceneNode::checkForCollisionWith(SceneNode& node, std::set<Pair>& collisionPairs)
{
        if (this != &node && this->collidesWith(node) && !isMarkedForRemoval() && !node.isMarkedForRemoval()) {
                collisionPairs.insert(std::minmax(this, &node));
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
        // Execute the command for this node, if the category matches the category defined in the command
        if (command.category & getCategory())
                command.action(*this, dt);
}

const Vector2d& SceneNode::getLocation() const { return mLocation; }
void SceneNode::setLocation(const Vector2d& newLocation) { mLocation = newLocation; }
const std::string& SceneNode::getName() const { return mName; }