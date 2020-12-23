//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include "Vector2d.h"

namespace turboHiker {

class BoundingBox;

/**
 * Basically a wrapper around a 2D vector class that also does bounds checking
 */
class WorldLocation
{

public:
        WorldLocation(const turboHiker::BoundingBox& worldBoundaries, const turboHiker::Vector2d& initialPosition,
                      const turboHiker::BoundingBox& sceneNodeBoundingBox);

        bool isOutOfBounds() const;

        void moveX(double xMovement);

        void moveY(double yMovement);

        void move(const Vector2d& movement);

        void setPosition(const Vector2d& newPosition);

        Vector2d getVectorPosition() const;

        const Vector2d& getVectorPositionRef() const;

private:

        const BoundingBox& mWorldBoundaries;
        const BoundingBox& mSceneNodeBoundingBox;
        Vector2d mWorldPosition;

        // TODO optional 'clamp to border' boolean? If true, automatically clamps, if false: not allowed?

};
} // namespace turboHiker
