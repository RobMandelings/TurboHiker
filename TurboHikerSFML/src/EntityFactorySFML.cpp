//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "BoundingBox.h"
#include "Entity.h"
#include "Hiker.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SceneNode.h"
#include "ShapeRenderComponent.h"
#include "Transformation.h"
#include "Vector2d.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <cassert>
#include <memory>

using namespace turboHiker;

turboHikerSFML::EntityFactorySFML::EntityFactorySFML(turboHikerSFML::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

std::unique_ptr<SceneNode> turboHikerSFML::EntityFactorySFML::createBackgroundRectangle(
    const BoundingBox& worldBorders) const
{

        sf::Vector2f rectangleSizeInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(worldBorders.getWidth(), worldBorders.getHeight()));

        std::unique_ptr<sf::RectangleShape> shape = std::make_unique<sf::RectangleShape>(rectangleSizeInPixels);
        shape->setOrigin(shape->getGlobalBounds().width / 2, shape->getGlobalBounds().height / 2);

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape), 0);

        return std::make_unique<SceneNode>(Vector2d(worldBorders.getWidth() / 2, worldBorders.getHeight() / 2),
                                           Vector2d(0, 0), std::move(shapeRenderComponent), "BackgroundRectangle");
}

std::unique_ptr<SceneNode> turboHikerSFML::EntityFactorySFML::createTestCircle(const Vector2d& location,
                                                                               const Vector2d& initialVelocity) const
{
        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(50.0f);
        shape->setOrigin(shape->getGlobalBounds().width / 2, shape->getGlobalBounds().height / 2);
        shape->setFillColor(sf::Color(100, 0, 0));

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape), 100);

        return std::make_unique<Entity>(location, Vector2d(0, 0), std::move(shapeRenderComponent), initialVelocity, "TestCircle");
}

std::unique_ptr<SceneNode> turboHikerSFML::EntityFactorySFML::createHiker(const Vector2d& location,
                                                                          const Vector2d& size,
                                                                          const Vector2d& initialVelocity,
                                                                          bool playerControlled) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<sf::Shape> shape =
            std::make_unique<sf::CircleShape>(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2);
        shape->setFillColor(sf::Color(100, 0, 200));
        shape->setOrigin(shape->getGlobalBounds().width / 2, shape->getGlobalBounds().height / 2);

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape), 100);

        return std::make_unique<Hiker>(location, size, std::move(shapeRenderComponent), initialVelocity,
                                       playerControlled);
}
