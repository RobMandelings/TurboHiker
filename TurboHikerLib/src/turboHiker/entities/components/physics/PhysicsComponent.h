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
class SceneNode;

class PhysicsComponent : public Updatable
{

public:
        PhysicsComponent(const Vector2d& initialLocation, std::unique_ptr<CollisionComponent> collisionComponent);
        void update(seconds dt) override;

        void handleCollision(const SceneNode& entity);

        const Vector2d& getLocation() const;

        void setWorldLocation(const Vector2d& newLocation);
        void move(const Vector2d& vector2D);

        const BoundingBox& getBoundingBox() const;

private:
        Vector2d mLocation;

        std::unique_ptr<CollisionComponent> mCollisionComponent;
};
} // namespace turboHiker