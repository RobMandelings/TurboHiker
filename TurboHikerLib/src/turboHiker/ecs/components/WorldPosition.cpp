//
// Created by Rob Mandelings on 22/12/2020.
//

#include "WorldPosition.h"

#include <iostream>
#include <cassert>

turboHiker::WorldPosition::WorldPosition(const turboHiker::BoundingBox& worldBoundaries,
                                         const turboHiker::Vector2d& initialPosition)
    : mWorldBoundaries(worldBoundaries), mWorldPosition(initialPosition)
{
        assert(!isOutOfBounds() && "The given initial position is not valid! It falls out of the world!");
}

bool turboHiker::WorldPosition::isOutOfBounds() const {
        // TODO check for bounds
        std::cout << "WorldPosition: out of bounds must be implemented!" << std::endl;
        return false;
}

void turboHiker::WorldPosition::moveX(double xMovement) {
        std::cout << "WorldPosition: out of bounds must be implemented!" << std::endl;
}

void turboHiker::WorldPosition::moveY(double yMovement) {

}

void turboHiker::WorldPosition::move(const turboHiker::Vector2d& movement) {
        moveX(movement.x);
        moveY(movement.y);
}
