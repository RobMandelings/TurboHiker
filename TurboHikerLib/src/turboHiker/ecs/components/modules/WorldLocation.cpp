//
// Created by Rob Mandelings on 22/12/2020.
//

#include "WorldLocation.h"

#include <cassert>
#include <iostream>

#include "BoundingBox.h"

turboHiker::WorldLocation::WorldLocation(const turboHiker::BoundingBox& worldBoundaries,
                                         const turboHiker::Vector2d& initialPosition,
                                         const turboHiker::BoundingBox& sceneNodeBoundingBox)
    : mWorldBoundaries(worldBoundaries), mWorldPosition(initialPosition), mSceneNodeBoundingBox(sceneNodeBoundingBox)
{
        assert(!isOutOfBounds() && "The given initial position is not valid! It falls out of the world!");
}

bool turboHiker::WorldLocation::isOutOfBounds() const
{
        // TODO check for bounds
        std::cout << "WorldLocation: out of bounds must be implemented!" << std::endl;
        return false;
}

void turboHiker::WorldLocation::moveX(double xMovement)
{
        assert(!isOutOfBounds() && "Position was invalid before move");
        mWorldPosition.x += xMovement;
        if (isOutOfBounds()) {
                // Direction was upward, so set the y position to the top of the world
                if (xMovement > 0) {
                        mWorldPosition.x = mWorldBoundaries.getRight() - mSceneNodeBoundingBox.getWidth();
                } else {
                        mWorldPosition.x = mWorldBoundaries.getLeft() + mSceneNodeBoundingBox.getWidth();
                }
        }
        assert(!isOutOfBounds());
}

void turboHiker::WorldLocation::moveY(double yMovement)
{
        assert(!isOutOfBounds() && "Position was invalid before move");
        mWorldPosition.y += yMovement;

        if (isOutOfBounds()) {
                // Direction was upward, so set the y position to the top of the world
                if (yMovement > 0) {
                        mWorldPosition.y = mWorldBoundaries.getTop() - mSceneNodeBoundingBox.getHeight();
                } else {
                        mWorldPosition.y = mWorldBoundaries.getBottom() + mSceneNodeBoundingBox.getHeight();
                }
        }
        assert(!isOutOfBounds());
}

void turboHiker::WorldLocation::move(const turboHiker::Vector2d& movement)
{
        assert(!isOutOfBounds() && "Position was invalid before move");
        moveX(movement.x);
        moveY(movement.y);
        assert(!isOutOfBounds());
}

void turboHiker::WorldLocation::setPosition(const turboHiker::Vector2d& newPosition)
{
        mWorldPosition.x = newPosition.x;
        mWorldPosition.y = newPosition.y;
        assert(!isOutOfBounds() && "The new position of the object is out of bounds of the world");
}

turboHiker::Vector2d turboHiker::WorldLocation::getVectorPosition() const { return mWorldPosition; }

const turboHiker::Vector2d& turboHiker::WorldLocation::getVectorPositionRef() const { return mWorldPosition; }
