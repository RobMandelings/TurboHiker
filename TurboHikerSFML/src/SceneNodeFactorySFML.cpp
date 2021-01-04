//
// Created by RobMa on 21/12/2020.
//

#include "SceneNodeFactorySFML.h"

#include "BoundingBox.h"
#include "FinishRenderer.h"
#include "HikerRenderer.h"
#include "LaneRenderer.h"
#include "PlayerHiker.h"
#include "SceneNode.h"
#include "Transformation.h"
#include "Vector2d.h"
#include <cassert>
#include <memory>

using namespace turboHiker;
using namespace turboHikerSFML;

turboHiker::SceneNodeFactorySFML::SceneNodeFactorySFML(turboHiker::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

SceneNode turboHiker::SceneNodeFactorySFML::createLane(const BoundingBox& laneDimensions) const
{

        Vector2d laneRectangleSizeInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(laneDimensions.getWidth(), laneDimensions.getHeight()));

        std::unique_ptr<LaneRenderer> laneRenderer = std::make_unique<LaneRenderer>(
            mWindowRenderer, sf::Vector2f(laneRectangleSizeInPixels.x, laneRectangleSizeInPixels.y));

        SceneNode lane(Vector2d(laneDimensions.getLeft() + laneDimensions.getWidth() / 2,
                                laneDimensions.getBottom() + laneDimensions.getHeight() / 2),
                       Vector2d(0, 0), std::move(laneRenderer), "Lane");

        return lane;
}

Finish SceneNodeFactorySFML::createFinish(const BoundingBox& finishDimensions) const
{

        Vector2d finishDimensionsInPixels = Transformation::get().scaleWorldCoordinatesToPixelCoordinates(
            Vector2d(finishDimensions.getWidth(), finishDimensions.getHeight()));

        std::unique_ptr<FinishRenderer> finishRenderer = std::make_unique<FinishRenderer>(
            mWindowRenderer, sf::Vector2f(finishDimensionsInPixels.x, finishDimensionsInPixels.y));

        Finish finish(Vector2d(finishDimensions.getLeft() + finishDimensions.getWidth() / 2,
                               finishDimensions.getBottom() + finishDimensions.getHeight() / 2),
                      Vector2d(finishDimensions.getWidth(), finishDimensions.getHeight()), std::move(finishRenderer), "Finish");

        return finish;
}

PlayerHiker turboHiker::SceneNodeFactorySFML::createPlayerHiker(double yLocation, const Vector2d& size,
                                                                double slowSpeed, double fastSpeed) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(0, 0, 255));

        return PlayerHiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), Vector2d(0, 0), "Player Hiker",
                           slowSpeed, fastSpeed);
}
Hiker SceneNodeFactorySFML::createStaticHiker(double yLocation, const Vector2d& size) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(0, 255, 0));

        return Hiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), Vector2d(0, 0), "Static Hiker");
}
Hiker SceneNodeFactorySFML::createMovingHiker(double yLocation, const Vector2d& size, const Vector2d& velocity) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        std::unique_ptr<HikerRenderer> hikerRenderer = std::make_unique<HikerRenderer>(
            mWindowRenderer, 1.5, float(Transformation::get().scaleWorldCoordinatesToPixelCoordinates(size).x / 2),
            sf::Color(255, 0, 0));

        return Hiker(Vector2d(0, yLocation), size, std::move(hikerRenderer), velocity, "Moving Hiker");
}
