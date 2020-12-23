//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORY_H
#define TURBOHIKER_ENTITYFACTORY_H

#include "WorldLocation.h"
namespace turboHiker {

class Entity;

/**
 * An Abstract Factory to create entities (Specific GameObjects). Their visual representation must be implemented by the
 * visualization library used (Such as SFML)
 */
class EntityFactory
{

        virtual std::unique_ptr<Entity> createStaticHiker(const Vector2d& location) const = 0;

};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITYFACTORY_H
