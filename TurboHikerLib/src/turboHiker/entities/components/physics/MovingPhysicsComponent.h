//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_MOVINGPHYSICSCOMPONENT_H
#define TURBOHIKER_MOVINGPHYSICSCOMPONENT_H

#include "PhysicsComponent.h"

namespace turboHiker {

/**
 * An extension to the basic PhysicsComponent that allows for moving in time
 */
class MovingPhysicsComponent : public PhysicsComponent
{

public:
        MovingPhysicsComponent(const Vector2d& initialLocation, std::unique_ptr<CollisionComponent> collisionComponent,
                               const Vector2d& initialVelocity);
        void update(seconds dt) override;

        void setVelocity(const Vector2d& newVelocity);

        void setVelocityX(double newVelocityX);

        void setVelocityY(double newVelocityY);

        const Vector2d& getVelocity() const;

private:
        Vector2d mVelocity;

};
} // namespace turboHiker

#endif // TURBOHIKER_MOVINGPHYSICSCOMPONENT_H
