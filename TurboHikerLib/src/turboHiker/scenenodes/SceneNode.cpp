//
// Created by RobMa on 19/12/2020.
//

#include "SceneNode.h"

#include <algorithm>
#include <cassert>
#include <set>

#include "BoundingBox.h"
#include "Renderer.h"

#include "Command.h"
#include "Vector2d.h"
#include "enums.h"

#include <iostream>
#include <utility>

using namespace turboHiker;

SceneNode::SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize, std::string name)
    : mLocation(initialLocation), mSize(boundingSize), mRenderer(nullptr), mName(std::move(name))
{
}

// TODO remove as well
SceneNode::SceneNode() : SceneNode(Vector2d(0, 0), Vector2d(0, 0), "World") {}

SceneNode::SceneNode(const SceneNode& other) : SceneNode(other.mLocation, other.mSize, other.mName)
{
        if (other.mRenderer != nullptr) {
                mRenderer = std::move(other.mRenderer->clone());
        }
}

void SceneNode::update(Updatable::seconds dt)
{
        // Do nothing by default
}

void turboHiker::SceneNode::updateRenderComponent(Updatable::seconds dt) const
{
        if (mRenderer) {
                mRenderer->update(dt, getLocation());
        }
}

void SceneNode::onCommand(const Command& command, seconds dt)
{
        // Execute the command for this node, if the category matches the category defined in the command
        if (command.category & getCategory()) {
                command.action(*this, dt);
        }
}

void turboHiker::SceneNode::render() const
{
        if (mRenderer) {
                mRenderer->render();
        }
}

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

const Vector2d& SceneNode::getLocation() const { return mLocation; }
const std::string& SceneNode::getName() const { return mName; }
const Vector2d& SceneNode::getSize() const { return mSize; }
unsigned int turboHiker::SceneNode::getCategory() const { return GameCategory::GameSceneNode; }

BoundingBox SceneNode::getBoundingBox() const
{
        return BoundingBox(getLocation().x - mSize.x / 2, getLocation().y - mSize.y / 2, mSize.x, mSize.y);
}

bool SceneNode::hasBoundingBox() const { return mSize.x != 0 && mSize.y != 0; }

void SceneNode::setSize(const Vector2d& boundingSize)
{
        assert(boundingSize.x >= 0);
        assert(boundingSize.y >= 0);
        mSize = boundingSize;
}

void SceneNode::setWidth(double width) { setSize(Vector2d(width, mSize.y)); }
void SceneNode::setHeight(double height) { setSize(Vector2d(mSize.x, height)); }
void SceneNode::setLocation(const Vector2d& newLocation) { mLocation = newLocation; }

void SceneNode::setRenderer(const Renderer& renderer) { mRenderer = renderer.clone(); }
