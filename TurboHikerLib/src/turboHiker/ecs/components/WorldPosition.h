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
class WorldPosition
{

public:
        WorldPosition(const BoundingBox& worldBoundaries, const Vector2d& initialPosition);

        bool isOutOfBounds() const;

        void moveX(double xMovement);

        void moveY(double yMovement);

        void move(const Vector2d& movement);

private:

        const BoundingBox& mWorldBoundaries;
        Vector2d mWorldPosition;

        // TODO optional 'clamp to border' boolean? If true, automatically clamps, if false: not allowed?

};
} // namespace turboHiker
