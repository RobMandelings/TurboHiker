//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_COLLISIONCOMPONENT_H
#define TURBOHIKER_COLLISIONCOMPONENT_H

#include "BoundingBox.h"

namespace turboHiker {

class SceneNode;

class CollisionComponent
{

public:
        CollisionComponent(const BoundingBox& boundingBox);

        void handleCollision(const SceneNode& entity);

        // TODO implement
        bool collidesWith(const SceneNode& entity);

        const BoundingBox& getBoundingBox() const;

private:

        BoundingBox mBoundingBox;
};
} // namespace turboHiker

#endif // TURBOHIKER_COLLISIONCOMPONENT_H
