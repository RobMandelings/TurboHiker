//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "BoundingBox.h"
#include "Entity.h"
#include "Hiker.h"
#include "HikerRenderer.h"
#include "LaneRenderer.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SceneNode.h"
#include "Transformation.h"
#include "Vector2d.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <cassert>
#include <memory>

using namespace turboHiker;
using namespace turboHikerSFML;

turboHiker::EntityFactorySFML::EntityFactorySFML(turboHiker::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

SceneNode turboHiker::EntityFactorySFML::createLane(const BoundingBox& laneDimensions) const
{

        Vector2d laneRectangleSizeInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(laneDimensions.getWidth(), laneDimensions.getHeight()));

        std::unique_ptr<LaneRenderer> laneRenderer = std::make_unique<LaneRenderer>(
            mWindowRenderer, sf::Vector2f(laneRectangleSizeInPixels.x, laneRectangleSizeInPixels.y));

        SceneNode lane(Vector2d(laneDimensions.getLeft() + laneDimensions.getWidth() / 2,
                                laneDimensions.getBottom() + laneDimensions.getHeight() / 2),
                       Vector2d(laneDimensions.getWidth() / 2, laneDimensions.getHeight() / 2), std::move(laneRenderer),
                       "Lane");

        return lane;
}

Hiker turboHiker::EntityFactorySFML::createPlayerHiker(double yLocation, const Vector2d& size) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(0, 0, 255));

        return Hiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), Vector2d(0, 0), true);
}
Hiker EntityFactorySFML::createStaticHiker(double yLocation, const Vector2d& size) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(0, 255, 0));

        return Hiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), Vector2d(0, 0), false);
}
Hiker EntityFactorySFML::createMovingHiker(double yLocation, const Vector2d& size, const Vector2d& velocity) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1.5, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(255, 0, 0));

        return Hiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), velocity, false);
}
