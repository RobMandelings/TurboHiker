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

bool Transformation::initialized() const { return mWorldView != nullptr && mWindowSize != nullptr && !mWorldBorders.empty(); }

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
        sf::Vector2f pixelCoordinates(
            worldCoordinates.x * (getWindowSize().getWidth() / getWorldView().getWorldXSize()),
            (mWorldBorders.getTop() - worldCoordinates.y) * (getWindowSize().getHeight() / getWorldView().getWorldYSize()));

        return pixelCoordinates;
}

std::mutex Transformation::mMutex;