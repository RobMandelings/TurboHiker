//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

#include "Updatable.h"

namespace turboHiker {

class Vector2d;

class BoundingBox;
class Velocity;
class WorldPosition;

class PhysicsSystem : public Updatable
{

public:
        PhysicsSystem(std::shared_ptr<WorldPosition>  position, std::shared_ptr<Velocity>  velocity,
                      std::shared_ptr<BoundingBox>  boundingBox);
        void update(seconds dt) override;

private:

        void move(const Vector2d& vector2D);

        std::shared_ptr<WorldPosition> mWorldPosition;
        std::shared_ptr<Velocity> mVelocity;
        std::shared_ptr<BoundingBox> mBoundingBox;

};
}