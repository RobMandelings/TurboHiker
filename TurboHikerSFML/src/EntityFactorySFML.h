//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_ENTITYFACTORYSFML_H
#define TURBOHIKER_ENTITYFACTORYSFML_H

#include "EntityFactory.h"
#include <memory>

namespace turboHiker {
class SceneNode;
}

/**
 * Creates Entities (A type of SceneNode that can move) with a specific VisualComponent created with SFML to give a
 * visual representation to these entities
 */
namespace turboHiker {

using namespace turboHiker;

class DrawableRenderer;

class EntityFactorySFML : public turboHiker::EntityFactory
{

public:
        EntityFactorySFML(DrawableRenderer& mWindowDrawer);

        std::unique_ptr<turboHiker::SceneNode> createTestCircle(const turboHiker::Vector2d& location,
                                                 const turboHiker::Vector2d& initialVelocity) const override;
        std::unique_ptr<Hiker> createHiker(const Vector2d& location, const Vector2d& size,
                                               const Vector2d& initialVelocity, bool playerControlled) const override;

        std::unique_ptr<turboHiker::SceneNode> createLane(const turboHiker::BoundingBox& laneDimensions) const override;

private:
        DrawableRenderer& mWindowRenderer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_ENTITYFACTORYSFML_H