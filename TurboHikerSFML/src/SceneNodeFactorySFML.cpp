//
// Created by RobMa on 21/12/2020.
//

#include "SceneNodeFactorySFML.h"

#include "BoundingBox.h"
#include "FinishRenderer.h"
#include "HikerRenderer.h"
#include "LaneRenderer.h"
#include "PlayerHiker.h"
#include "StaticHiker.h"
#include "RunningHiker.h"
#include "SceneNode.h"
#include "Transformation.h"
#include "Vector2d.h"
#include <cassert>

using namespace turboHiker;
using namespace turboHikerSFML;

turboHiker::SceneNodeFactorySFML::SceneNodeFactorySFML(turboHiker::DrawableRenderer& mWindowDrawer)
    : mWindowRenderer(mWindowDrawer)
{
}

SceneNode turboHiker::SceneNodeFactorySFML::createLane(const BoundingBox& laneDimensions) const
{

        Vector2d laneRectangleSizeInPixels = Transformation::get().scaleWorldCoordsToPixelCoords(
            Vector2d(laneDimensions.getWidth(), laneDimensions.getHeight()));

        LaneRenderer laneRenderer =
            LaneRenderer(mWindowRenderer, sf::Vector2f(laneRectangleSizeInPixels.x, laneRectangleSizeInPixels.y));

        SceneNode lane(Vector2d(laneDimensions.getLeft() + laneDimensions.getWidth() / 2,
                                laneDimensions.getBottom() + laneDimensions.getHeight() / 2),
                       Vector2d(0, 0), "Lane");

        lane.setRenderer(laneRenderer);

        return lane;
}

Finish SceneNodeFactorySFML::createFinish(const BoundingBox& finishDimensions) const
{

        Vector2d finishDimensionsInPixels = Transformation::get().scaleWorldCoordsToPixelCoords(
            Vector2d(finishDimensions.getWidth(), finishDimensions.getHeight()));

        FinishRenderer finishRenderer =
            FinishRenderer(mWindowRenderer, sf::Vector2f(finishDimensionsInPixels.x, finishDimensionsInPixels.y));

        Finish finish(finishDimensions);
        finish.setRenderer(finishRenderer);

        return finish;
}

PlayerHiker turboHiker::SceneNodeFactorySFML::createPlayerHiker(double yLocation, const Vector2d& size,
                                                                double slowSpeed, double fastSpeed) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        HikerRenderer hikerRenderer =
            HikerRenderer(mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordsToPixelCoords(size).x / 2),
                          sf::Color(0, 0, 255));

        PlayerHiker playerHiker(Vector2d(0, yLocation), size, "Player Hiker", slowSpeed, fastSpeed);
        playerHiker.setRenderer(hikerRenderer);

        return playerHiker;
}
StaticHiker SceneNodeFactorySFML::createStaticHiker(double yLocation, const Vector2d& size) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        HikerRenderer hikerRenderer =
            HikerRenderer(mWindowRenderer, 1, float(Transformation::get().scaleWorldCoordsToPixelCoords(size).x / 2),
                          sf::Color(0, 255, 0));

        StaticHiker staticHiker(Vector2d(0, yLocation), size, "Static Hiker");
        staticHiker.setRenderer(hikerRenderer);
        return staticHiker;
}
RunningHiker SceneNodeFactorySFML::createMovingHiker(double yLocation, const Vector2d& size, const Vector2d& velocity) const
{
        assert(size.x == size.y && "Must be a square in order for the shape to be a circle");

        HikerRenderer hikerRenderer =
            HikerRenderer(mWindowRenderer, 1.5, float(Transformation::get().scaleWorldCoordsToPixelCoords(size).x / 2),
                          sf::Color(255, 0, 0));

        RunningHiker runningHiker(Vector2d(0, yLocation), size, velocity, "Moving Hiker");
        runningHiker.setRenderer(hikerRenderer);

        return runningHiker;
}
