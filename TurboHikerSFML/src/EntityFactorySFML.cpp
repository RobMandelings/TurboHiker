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

turboHiker::EntityFactorySFML::EntityFactorySFML(turboHiker::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

std::unique_ptr<SceneNode> turboHiker::EntityFactorySFML::createLane(const BoundingBox& laneDimensions) const
{

        Vector2d laneRectangleSizeInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(laneDimensions.getWidth(), laneDimensions.getHeight()));

        std::unique_ptr<sf::RectangleShape> laneShape = std::make_unique<sf::RectangleShape>(
            sf::Vector2f(laneRectangleSizeInPixels.x, laneRectangleSizeInPixels.y));
        laneShape->setOrigin(laneShape->getGlobalBounds().width / 2, laneShape->getGlobalBounds().height / 2);

        laneShape->setFillColor(sf::Color(200, 200, 200));
        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(laneShape), 0);

        // Bounding sizes always have their center at the origin. So if you have a width of 50, the bounding size would be 25
        std::unique_ptr<SceneNode> lane =
            std::make_unique<SceneNode>(Vector2d(laneDimensions.getLeft() + laneDimensions.getWidth() / 2,
                                                 laneDimensions.getBottom() + laneDimensions.getHeight() / 2),
                                        Vector2d(laneDimensions.getWidth() / 2, laneDimensions.getHeight() / 2), std::move(shapeRenderComponent), "Lane");

        Vector2d borderRectangleSizeInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(laneDimensions.getWidth() / 50, laneDimensions.getHeight()));

        std::unique_ptr<sf::RectangleShape> borderShape = std::make_unique<sf::RectangleShape>(
            sf::Vector2f(borderRectangleSizeInPixels.x, borderRectangleSizeInPixels.y));
        borderShape->setOrigin(borderShape->getGlobalBounds().width / 2, borderShape->getGlobalBounds().height / 2);
        borderShape->setFillColor(sf::Color::Cyan);

        std::unique_ptr<ShapeRenderComponent> borderShapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(borderShape), 0);
        std::unique_ptr<SceneNode> laneBorder = std::make_unique<SceneNode>(
            Vector2d(laneDimensions.getLeft() + borderRectangleSizeInPixels.x / 2.0, laneDimensions.getHeight() / 2),
            Vector2d(0, 0), std::move(borderShapeRenderComponent), "LaneBorder");
        lane->attachChild(std::move(laneBorder));

        return lane;

        // return ;
}

std::unique_ptr<SceneNode> turboHiker::EntityFactorySFML::createTestCircle(const Vector2d& location,
                                                                           const Vector2d& initialVelocity) const
{
        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(50.0f);
        shape->setOrigin(shape->getGlobalBounds().width / 2, shape->getGlobalBounds().height / 2);
        shape->setFillColor(sf::Color(100, 0, 0));

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape), 100);

        return std::make_unique<Entity>(location, Vector2d(0, 0), std::move(shapeRenderComponent), initialVelocity,
                                        "TestCircle");
}

std::unique_ptr<Hiker> turboHiker::EntityFactorySFML::createHiker(const Vector2d& location, const Vector2d& size,
                                                                  const Vector2d& initialVelocity,
                                                                  bool playerControlled) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(
            Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2);
        shape->setFillColor(sf::Color(0, 0, 100));
        shape->setOrigin(shape->getGlobalBounds().width / 2, shape->getGlobalBounds().height / 2);

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent =
            std::make_unique<ShapeRenderComponent>(mWindowRenderer, std::move(shape), 1);

        return std::make_unique<Hiker>(location, size, std::move(shapeRenderComponent), initialVelocity,
                                       playerControlled);
}
