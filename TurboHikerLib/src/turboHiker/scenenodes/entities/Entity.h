//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include "SceneNode.h"

namespace turboHiker {

/**
 * An entity is a scene node which can move over time as it has velocity
 */
class Entity : public SceneNode
{

public:
        /**
         * Simple constructor
         * @param location: the initial location (in world coordinates) of the entity
         * @param size: the bounding size of the entity. Used to calculate the current boundingBox
         * @param velocity: the initial velocity of the entity
         * @param name: the name of the entity
         */
        Entity(const Vector2d& location, const Vector2d& size, const Vector2d& velocity,
               const std::string& name);

        /**
         * Simple setter
         * @param velocity: the new velocity of the entity
         */
        void setVelocity(const Vector2d& velocity);

        /**
         * Simple getter
         * @return the current velocity of the entity
         */
        Vector2d getVelocity() const;

        /**
         * Accelerate (or decelerate) the entity by the given vector of acceleration
         * @param acceleration: the given acceleration to accelerate the entity with
         */
        void accelerate(const Vector2d& acceleration);

        /**
         * Updates the entity using the given delta time
         * @param dt: the delta time (timestep)
         */
        void update(seconds dt) override;

        /**
         * Simple getter
         * @return the category of the entity, may belong to multiple entities
         */
        unsigned int getCategory() const override;

protected:
        /**
         * The current velocity of the entity
         */
        Vector2d mVelocity;

private:
};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITY_H
