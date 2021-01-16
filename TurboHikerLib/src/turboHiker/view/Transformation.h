//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include "BoundingBox.h"
#include "WindowSize.h"
#include "WorldView.h"

#include <memory>
#include <mutex>
#include <turboHiker/utils/maths/Vector2d.h>
#include <utility>

namespace turboHiker {
class BoundingBox;
class Vector2d;
class Hiker;
} // namespace turboHiker

namespace turboHiker {

using namespace turboHiker;

// TODO implement scaling/zooming: draw the scenenodes smaller or bigger depending on changes in view
/**
 * Singleton class that creates a view system for the world. View can be modified / updated. In the end it comes down to
 * converting World Coordinates into pixel coordinate values, without specifically knowing the visual implementation for
 * this.
 */
class Transformation
{

public:

        /**
         * Deleted the copy constructor as its a singleton
         */
        Transformation(Transformation& other) = delete;

        /**
         * Deleted the assignment operator as its a singleton
         */
        void operator=(const Transformation&) = delete;

        /**
         * Simple getter
         * @return the instance of the transformation class
         */
        static Transformation& get();

        /**
         * Initialize the transformation class with current windowSize and World Borders
         * @param windowSize: the windowSize to initialize the transformation class with
         * @param worldBorders: the world borders
         */
        void initialize(const WindowSize& windowSize, const turboHiker::BoundingBox& worldBorders);

        /**
         * Sets the height of the world you can see, updating other values as well to keep the aspect ratio the same
         * @param worldViewHeight: the new world view height
         */
        void setWorldViewHeight(double worldViewHeight);
        
        /**
         * Sets the height of the world you can see, updating other values as well to keep the aspect ratio the same
         * @param worldViewHeight: the new world view height
         */
        void setWorldViewWidth(double worldViewWidth);

        /**
         * Sets the width of the world you can see, updating other values as well to keep the aspect ratio the same
         * @param worldViewWidth: the new world view width
         */
        const WorldView& getWorldView() const;

        /**
         * Gets the current coordinate which represents the center-of-view.
         * @return the center of view of the world
         */
        const Vector2d& getWorldViewCenter() const;

        /**
         * Sets the world view to a new center point
         * @param center
         */
        void setWorldViewCenter(const Vector2d& center);

        /**
         * Sets the x coordinate center of view
         * @param x: the x coordinate
         */
        void setWorldViewCenterX(double x);

        void setWorldViewCenterY(double y);

        void setWindowSize(const WindowSize& windowSize);

        const WindowSize& getWindowSize() const;

        Vector2d convertWorldCoordinatesToPixelCoordinates(const turboHiker::Vector2d& worldCoordinates) const;

        /**
         * Converts the given worldCoordinates to its corresponding pixel values of the screen, assuming that these
         * world coordinates have already been translated by the center of view
         * @param worldCoordinates
         * @return
         */
        Vector2d scaleWorldCoordsToPixelCoords(const Vector2d& worldCoordinates) const;

        turboHiker::BoundingBox convertWorldBoundingBoxToVisualBoundingBox(
            const turboHiker::BoundingBox& worldBoundingBox) const;

        /**
         * Asserts that the world coordinates converted to the pixel coordinates are ratio 1:1, meaning that objects are
         * not squeezed / stretched. E.g. If you can view more of the world in the width, the window must be wider as
         * well. You should also be able to see more of the height of the world then.
         */
        bool checkOneToOneRatio() const;

private:
        explicit Transformation();

        bool initialized() const;

private:
        static std::mutex mMutex;

        std::unique_ptr<WorldView> mWorldView;

        std::unique_ptr<WindowSize> mWindowSize;

        /** Needed to translate the definition of what is the top of the world and what is the bottom */
        turboHiker::BoundingBox mWorldBorders;
};

} // namespace turboHiker

#endif // TURBOHIKER_TRANSFORMATION_H
