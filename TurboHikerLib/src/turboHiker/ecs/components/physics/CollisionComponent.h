//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_COLLISIONCOMPONENT_H
#define TURBOHIKER_COLLISIONCOMPONENT_H

#include "BoundingBox.h"

namespace turboHiker {

class Entity;

class CollisionComponent
{

public:

        void handleCollision(const Entity& entity);

        // TODO implement
        bool collidesWith(const Entity& entity);

        const BoundingBox& getBoundingBox() const;

private:

        BoundingBox mBoundingBox;
};
} // namespace turboHiker

#endif // TURBOHIKER_COLLISIONCOMPONENT_H
