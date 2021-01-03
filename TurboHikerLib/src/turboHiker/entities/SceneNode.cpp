//
// Created by RobMa on 19/12/2020.
//

#include "SceneNode.h"

#include <algorithm>
#include <cassert>
#include <set>

#include "BoundingBox.h"
#include "CollisionComponent.h"
#include "SceneNodeRenderer.h"

#include "Command.h"

#include "WorldLocation.h"

#include <iostream>
#include <turboHiker/Category.h>
#include <utility>

using namespace turboHiker;

SceneNode::SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize,
                     std::unique_ptr<SceneNodeRenderer> renderComponent, std::string name)
    : mLocation(initialLocation), mBoundingSize(boundingSize), mRenderComponent(std::move(renderComponent)),
      mName(std::move(name))
{
}

// TODO remove as well
SceneNode::SceneNode() : SceneNode(Vector2d(0, 0), Vector2d(0, 0), nullptr, "World") {}

SceneNode::SceneNode(const SceneNode& other)
    : mBoundingSize(other.mBoundingSize), mLocation(other.mLocation), mName(other.mName)
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
        return BoundingBox(getLocation().x - mBoundingSize.x / 2, getLocation().y - mBoundingSize.y / 2,
                           mBoundingSize.x, mBoundingSize.y);
}

bool SceneNode::hasBoundingBox() const { return mBoundingSize.x != 0 && mBoundingSize.y != 0; }

bool SceneNode::collidesWith(const SceneNode& other) const
{
        if (&other != this && hasBoundingBox() && other.hasBoundingBox()) {
                return collidesWith(other.getBoundingBox());
        }
        return false;
}

bool SceneNode::collidesWith(const BoundingBox& boundingBox) const
{
        // Check if one rectangle is on the left side of the other
        if (this->getBoundingBox().getLeft() > boundingBox.getRight() ||
            boundingBox.getLeft() > this->getBoundingBox().getRight()) {
                return false;
        }

        if (this->getBoundingBox().getBottom() > boundingBox.getTop() ||
            boundingBox.getBottom() > this->getBoundingBox().getTop()) {
                return false;
        }

        return true;
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

const Vector2d& SceneNode::getSize() const { return mBoundingSize; }

const Vector2d& SceneNode::getLocation() const { return mLocation; }
void SceneNode::setLocation(const Vector2d& newLocation) { mLocation = newLocation; }
const std::string& SceneNode::getName() const { return mName; }