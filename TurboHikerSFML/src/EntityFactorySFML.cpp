//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "BoundingBox.h"
#include "Entity.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SceneNode.h"
#include "ShapeRenderComponent.h"
#include "Vector2d.h"
#include <memory>

using namespace turboHiker;

turboHikerSFML::EntityFactorySFML::EntityFactorySFML(turboHikerSFML::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

std::unique_ptr<SceneNode> turboHikerSFML::EntityFactorySFML::createTestCircle(const Vector2d& location,
                                                                            const Vector2d& initialVelocity) const
{
        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(50.0f);
        shape->setFillColor(sf::Color(100, 0, 0));

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent = std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape));

        return std::make_unique<Entity>(Vector2d(50, 50), nullptr, std::move(shapeRenderComponent), Vector2d(35, 2));

}
