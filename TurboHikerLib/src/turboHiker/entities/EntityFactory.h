//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include "Hiker.h"
#include "SceneNode.h"
#include "WorldLocation.h"

namespace turboHiker {

/**
 * An Abstract Factory to create entities (Specific GameObjects). Their visual representation must be implemented by the
 * visualization library used (Such as SFML)
 */
class EntityFactory
{

public:
        virtual SceneNode createLane(const BoundingBox& laneDimensions) const = 0;

        virtual Hiker createHiker(double yLocation, const Vector2d& size, const Vector2d& initialVelocity,
                                  bool playerControlled) const = 0;
};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITYFACTORY_H
