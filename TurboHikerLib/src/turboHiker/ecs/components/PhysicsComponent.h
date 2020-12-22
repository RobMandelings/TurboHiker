//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

#include "Updatable.h"
#include "WorldPosition.h"
#include "BoundingBox.h"

namespace turboHiker {

class Vector2d;

class PhysicsComponent : public Updatable
{

public:
        PhysicsComponent(const WorldPosition& initialWorldPosition, const BoundingBox& boundingBox);
        void update(seconds dt) override;

        const WorldPosition& getWorldPosition() const;

        void setWorldLocation(const Vector2d& newPosition);
        void move(const Vector2d& vector2D);

        const BoundingBox& getBoundingBox() const;

private:

        WorldPosition mWorldPosition;
        BoundingBox mBoundingBox;

};
} // namespace turboHiker