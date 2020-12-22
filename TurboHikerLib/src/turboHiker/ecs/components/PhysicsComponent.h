//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

#include "Updatable.h"

namespace turboHiker {

class Vector2d;

class BoundingBox;
class WorldPosition;

class PhysicsComponent : public Updatable
{

public:
        PhysicsComponent(std::unique_ptr<WorldPosition> position, std::unique_ptr<Vector2d> velocity,
                      std::unique_ptr<BoundingBox> boundingBox);
        void update(seconds dt) override;

        const WorldPosition& getWorldPosition() const;

        void setWorldLocation(const Vector2d& newPosition);
        void move(const Vector2d& vector2D);

        const BoundingBox& getBoundingBox() const;

private:

        std::unique_ptr<WorldPosition> mWorldPosition;
        std::unique_ptr<BoundingBox> mBoundingBox;

        std::unique_ptr<Vector2d> mVelocity;
};
} // namespace turboHiker