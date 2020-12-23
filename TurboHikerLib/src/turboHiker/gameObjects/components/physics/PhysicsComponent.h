//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

#include "BoundingBox.h"
#include "Updatable.h"
#include "WorldLocation.h"

namespace turboHiker {

class CollisionComponent;
class Vector2d;
class Entity;

class PhysicsComponent : public Updatable
{

public:
        PhysicsComponent(const WorldLocation& worldPosition, std::unique_ptr<CollisionComponent> collisionComponent);
        void update(seconds dt) override;

        void handleCollision(const Entity& entity);

        const WorldLocation& getWorldLocation() const;

        void setWorldLocation(const Vector2d& newLocation);
        void move(const Vector2d& vector2D);

        const BoundingBox& getBoundingBox() const;

private:
        WorldLocation mWorldLocation;

        std::unique_ptr<CollisionComponent> mCollisionComponent;

};
} // namespace turboHiker