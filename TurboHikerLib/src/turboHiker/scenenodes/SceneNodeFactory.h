//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_SCENENODEFACTORY_H
#define TURBOHIKER_SCENENODEFACTORY_H

#include "BoundingBox.h"
#include "Finish.h"
#include "PlayerHiker.h"

namespace turboHiker {

class SceneNode;
class Hiker;
class Vector2d;

/**
 * An Abstract Factory to create scenenodes (Specific GameObjects). Their visual representation must be implemented by the
 * visualization library used (Such as SFML)
 */
class SceneNodeFactory
{

public:
        virtual SceneNode createLane(const BoundingBox& laneDimensions) const = 0;

        virtual Finish createFinish(const BoundingBox& finishDimensions) const = 0;

        virtual PlayerHiker createPlayerHiker(double yLocation, const Vector2d& size, double slowSpeed,
                                        double fastSpeed) const = 0;

        virtual Hiker createStaticHiker(double yLocation, const Vector2d& size) const = 0;

        virtual Hiker createMovingHiker(double yLocation, const Vector2d& size,
                                        const Vector2d& velocity) const = 0;
};
} // namespace turboHiker

#endif // TURBOHIKER_SCENENODEFACTORY_H
