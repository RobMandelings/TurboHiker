//
// Created by RobMa on 19/12/2020.
//

#include "Transformation.h"

#include "BoundingBox.h"
#include <cassert>

using namespace turboHiker;
using namespace turboHikerSFML;

Transformation::Transformation() : mWorldView(nullptr), mWindowSize(nullptr), mWorldBorders(0, 0, 0, 0) {}

Transformation& Transformation::get()
{
        std::lock_guard<std::mutex> lock(mMutex);

        static Transformation instance;

        return instance;
}

void Transformation::initialize(const WorldView& worldView, const WindowSize& windowSize,
                                const BoundingBox& worldBorders)
{
        std::cout << "Initializing!" << std::endl;
        mWorldView = std::make_unique<WorldView>(worldView);
        mWindowSize = std::make_unique<WindowSize>(windowSize);
        mWorldBorders = worldBorders;
}

bool Transformation::initialized() const
{
        return mWorldView != nullptr && mWindowSize != nullptr && !mWorldBorders.empty();
}

WorldView& Transformation::getWorldView() const
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        return *mWorldView;
}

WindowSize& Transformation::getWindowSize() const
{
        assert(initialized());
        return *mWindowSize;
}

sf::Vector2f Transformation::convertWorldCoordinatesToPixelCoordinates(const Vector2d& worldCoordinates) const
{

        const Vector2d& worldViewCenter = getWorldView().getWorldViewCenter();

        // These are the translated world coordinates, where the center of view has been taken into account as well
        sf::Vector2f pixelCoordinates =
            sf::Vector2f(worldCoordinates.x - (worldViewCenter.x - (getWorldView().getWorldXSize() / 2)),
                         worldCoordinates.y - (worldViewCenter.y - (getWorldView().getWorldYSize() / 2)));

        // Scale these translated world coordinates to their corresponding pixel values
        scaleWorldCoordinatesToPixelCoordinates(pixelCoordinates);

        // The top of the screen is at y = 0, the bottom at mWindowSize.getHeight(). So the current pixel coordinates
        // need to be converted to not appear upside-down
        pixelCoordinates.y = float(mWindowSize->getHeight()) - pixelCoordinates.y;

        return pixelCoordinates;
}

void Transformation::scaleWorldCoordinatesToPixelCoordinates(sf::Vector2f& worldCoordinates) const
{
        worldCoordinates.x = worldCoordinates.x * (getWindowSize().getWidth() / getWorldView().getWorldXSize());
        worldCoordinates.y = worldCoordinates.y * float(getWindowSize().getHeight()) / getWorldView().getWorldYSize();
}

std::mutex Transformation::mMutex;