//
// Created by RobMa on 19/12/2020.
//

#include "Transformation.h"

#include "BoundingBox.h"
#include <cassert>
#include <cmath>

using namespace turboHiker;
using namespace turboHiker;

Transformation::Transformation() : mWorldView(nullptr), mWindowSize(nullptr), mWorldBorders(0, 0, 0, 0) {}

Transformation& Transformation::get()
{
        std::lock_guard<std::mutex> lock(mMutex);

        static Transformation instance;

        return instance;
}

void Transformation::initialize(const WindowSize& windowSize, const turboHiker::BoundingBox& worldBorders)
{
        std::cout << "Initializing!" << std::endl;

        double worldViewHeight = windowSize.getHeight() / double(windowSize.getWidth()) * worldBorders.getWidth();

        mWorldView = std::make_unique<WorldView>(WorldView(worldBorders.getWidth(), worldViewHeight,
                                                           Vector2d(worldBorders.getWidth() / 2, worldViewHeight / 2)));
        mWindowSize = std::make_unique<WindowSize>(windowSize);
        mWorldBorders = worldBorders;

        assert(checkOneToOneRatio());
}

bool Transformation::initialized() const
{
        return mWorldView != nullptr && mWindowSize != nullptr && !mWorldBorders.empty();
}

void Transformation::setWorldViewWidth(double worldViewWidth)
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        double worldViewHeight = getWindowSize().getHeight() / double(getWindowSize().getWidth()) * worldViewWidth;
        mWorldView->setWidth(worldViewWidth);
        mWorldView->setHeight(worldViewHeight);

        assert(checkOneToOneRatio());
}

void Transformation::setWorldViewHeight(double worldViewHeight)
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        double worldViewWidth = getWindowSize().getWidth() / double(getWindowSize().getHeight()) * worldViewHeight;

        mWorldView->setWidth(worldViewWidth);
        mWorldView->setHeight(worldViewHeight);
        assert(checkOneToOneRatio());
}

const WorldView& Transformation::getWorldView() const {
        return *mWorldView;
}
void Transformation::setWorldViewCenter(const Vector2d& newCenter)
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        mWorldView->setWorldViewCenter(newCenter);
}

void Transformation::setWorldViewCenterX(double x)
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        mWorldView->setWorldViewCenter(Vector2d(x, getWorldViewCenter().y));
}

void Transformation::setWorldViewCenterY(double y)
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        mWorldView->setWorldViewCenter(Vector2d(getWorldViewCenter().x, y));
}

void Transformation::setWindowSize(const WindowSize& newWindowSize)
{

        // Calculate the new world view width based on the new window size, old windowSize and old world view width
        double newWorldViewWidth =
            double(newWindowSize.getWidth()) / mWindowSize->getWidth() * mWorldView->getWorldViewWidth();

        // Set the window size to the new value
        *mWindowSize = newWindowSize;

        // Set the new worldViewWidth to the calculated value. Automatically calculates the new world view height
        // (always in function of the world view width) to keep the 1:1 ratio
        setWorldViewWidth(newWorldViewWidth);

        // mWorldView->setWorldViewCenter(<#initializer #>);
}

const Vector2d& Transformation::getWorldViewCenter() const
{
        assert(initialized() && "Transformation singleton not yet initialized with required values (View and window)!");
        return mWorldView->getWorldViewCenter();
}

const WindowSize& Transformation::getWindowSize() const
{
        assert(initialized());
        return *mWindowSize;
}

Vector2d Transformation::convertWorldCoordinatesToPixelCoordinates(const Vector2d& worldCoordinates) const
{

        assert(initialized());

        const Vector2d& worldViewCenter = mWorldView->getWorldViewCenter();

        // These are the translated world coordinates, where the center of view has been taken into account as well
        Vector2d translatedWorldCoordinates(
            worldCoordinates.x - (worldViewCenter.x - (mWorldView->getWorldViewWidth() / 2)),
            worldCoordinates.y - (worldViewCenter.y - (mWorldView->getWorldViewHeight() / 2)));

        // Scale these translated world coordinates to their corresponding pixel values
        Vector2d pixelCoordinates = scaleWorldCoordinatesToPixelCoordinates(translatedWorldCoordinates);

        // The top of the screen is at y = 0, the bottom at mWindowSize.getHeight(). So the current pixel coordinates
        // need to be converted to not appear upside-down
        pixelCoordinates.y = float(mWindowSize->getHeight()) - pixelCoordinates.y;

        return pixelCoordinates;
}

Vector2d Transformation::scaleWorldCoordinatesToPixelCoordinates(const Vector2d& worldCoordinates) const
{
        return Vector2d(worldCoordinates.x * (getWindowSize().getWidth() / mWorldView->getWorldViewWidth()),
                            worldCoordinates.y * float(getWindowSize().getHeight()) / mWorldView->getWorldViewHeight());
}

bool Transformation::checkOneToOneRatio() const
{
        // The calculates values must be equal, so take the difference first, take the absolute value and check if they are less than 'epsilon'
        double comparisonValue = std::abs((getWindowSize().getHeight() / double(mWindowSize->getWidth())) -
            (mWorldView->getWorldViewHeight() / mWorldView->getWorldViewWidth()));

        // Normal epsilon as numeric limit was not good enough as this sometimes returned false even thought the ratio was 1:1. Epsilon * 10 is still safe to use
        return comparisonValue < std::numeric_limits<double>::epsilon() * 10;
}

std::mutex Transformation::mMutex;