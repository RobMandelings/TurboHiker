//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

#include "BoundingBox.h"
#include "Updatable.h"
#include "WorldLocation.h"

namespace turboHiker {

class AbstractCollisionComponent;
class Vector2d;

class PhysicsComponent : public Updatable
{

public:
        PhysicsComponent(const WorldLocation& initialWorldPosition, const BoundingBox& boundingBox);
        void update(seconds dt) override;

        const WorldLocation& getWorldLocation() const;

        void setWorldLocation(const Vector2d& newLocation);
        void move(const Vector2d& vector2D);

        const BoundingBox& getBoundingBox() const;

private:
        WorldLocation mWorldLocation;

        std::unique_ptr<AbstractCollisionComponent> mCollisionComponent;

};
} // namespace turboHiker