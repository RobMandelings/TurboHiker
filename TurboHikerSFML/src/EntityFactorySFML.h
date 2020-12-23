//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORYSFML_H
#define TURBOHIKER_ENTITYFACTORYSFML_H

#include "turboHiker/gameObjects/EntityFactory.h"
#include <memory>

/**
 * Creates Entities (A type of Entity that can move) with a specific VisualComponent created with SFML to give a
 * visual representation to these entities
 */
class EntityFactorySFML : turboHiker::EntityFactory
{

        std::unique_ptr<Entity> createStaticHiker(const turboHiker::WorldLocation& worldLocation) const override;
};

#endif // TURBOHIKER_ENTITYFACTORYSFML_H