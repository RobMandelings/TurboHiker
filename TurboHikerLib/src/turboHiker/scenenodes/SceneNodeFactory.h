//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_SCENENODEFACTORY_H
#define TURBOHIKER_SCENENODEFACTORY_H

#include "BoundingBox.h"
#include "Finish.h"
#include "PlayerHiker.h"
#include <RunningHiker.h>
#include <StaticHiker.h>

namespace turboHiker {

class SceneNode;
class Hiker;
class Vector2d;

/**
 * An Abstract Factory to create scenenodes (Specific GameObjects). Their visual representation must be implemented by
 * the visualization library used (Such as SFML)
 */
class SceneNodeFactory
{

public:
        /**
         * Creates a lane with given dimensions
         * @param dimensions: the dimensions of the lane, in world coordinates
         * @return the created Lane (SceneNode)
         */
        virtual SceneNode createLane(const BoundingBox& dimensions) const = 0;

        /**
         * Creates a finish with given dimensions
         * @param dimensions: the dimensions of the finish, in world coordinates
         * @return the created Finish
         */
        virtual Finish createFinish(const BoundingBox& dimensions) const = 0;

        /**
         * Creates a PlayerHiker object
         * @param yLocation: the initial y coordinate of the player
         * @param size: the size of the player, in world coordinates
         * @param slowSpeed: the speed at which the player moves slow
         * @param fastSpeed: the speed at which the player moves fast
         * @return the created PlayerHiker
         */
        virtual PlayerHiker createPlayerHiker(double yLocation, const Vector2d& size, double slowSpeed,
                                              double fastSpeed) const = 0;

        /**
         * Creates a StaticHiker object
         * @param yLocation: the initial y coordinate of the player
         * @param size: the size of the hiker, in world coordinates
         * @return the created StaticHiker
         */
        virtual StaticHiker createStaticHiker(double yLocation, const Vector2d& size) const = 0;

        /**
         * Creates a RunningHiker object
         * @param yLocation: the initial y coordinate of the player, in world coordinates
         * @param size: the size of the hiker
         * @return the created RunningHiker
         */
        virtual RunningHiker createMovingHiker(double yLocation, const Vector2d& size,
                                               const Vector2d& velocity) const = 0;
};
} // namespace turboHiker

#endif // TURBOHIKER_SCENENODEFACTORY_H
