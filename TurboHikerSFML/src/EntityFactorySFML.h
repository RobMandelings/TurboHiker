//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORYSFML_H
#define TURBOHIKER_ENTITYFACTORYSFML_H

#include "turboHiker/gameObjects/EntityFactory.h"
#include <memory>

namespace turboHiker {
class Entity;
}

/**
 * Creates Entities (A type of Entity that can move) with a specific VisualComponent created with SFML to give a
 * visual representation to these entities
 */
namespace turboHikerSFML {

class EntityFactorySFML : public turboHiker::EntityFactory
{

        std::unique_ptr<turboHiker::Entity> createStaticHiker(const turboHiker::Vector2d& location) const override;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_ENTITYFACTORYSFML_H