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

class WindowRenderer;

class EntityFactorySFML : public turboHiker::EntityFactory
{

public:
        EntityFactorySFML(WindowRenderer& mWindowDrawer);

        std::unique_ptr<turboHiker::Entity> createTestCircle(const turboHiker::Vector2d& location,
                                                 const turboHiker::Vector2d& initialVelocity) const override;

private:
        WindowRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_ENTITYFACTORYSFML_H