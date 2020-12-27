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

// TODO implement scaling/zooming: draw the entities smaller or bigger depending on changes in view
class Transformation
{

public:
        Transformation(Transformation& other) = delete;

        void operator=(const Transformation&) = delete;

        static Transformation& get();

        void initialize(const WindowSize& windowSize, const turboHiker::BoundingBox& worldBorders);

        void setWorldViewHeight(double worldViewHeight);

        void setWorldViewWidth(double worldViewWidth);

        const Vector2d& getWorldViewCenter() const;

        void setWorldViewCenter(const Vector2d& newCenter);

        void setWorldViewCenterX(double x);

        void setWorldViewCenterY(double y);

        void setWindowSize(const WindowSize& newWindowSize);

        const WindowSize& getWindowSize() const;

        Vector2d convertWorldCoordinatesToPixelCoordinates(const turboHiker::Vector2d& worldCoordinates) const;

        /**
         * Converts the given worldCoordinates to its corresponding pixel values of the screen, assuming that these
         * world coordinates have already been translated by the center of view
         * @param worldCoordinates
         * @return
         */
        Vector2d scaleWorldCoordinatesToPixelCoordinates(const Vector2d& worldCoordinates) const;

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
        static Transformation* mInstance;

        static std::mutex mMutex;

        std::unique_ptr<WorldView> mWorldView;

        std::unique_ptr<WindowSize> mWindowSize;

        /** Needed to translate the definition of what is the top of the world and what is the bottom */
        turboHiker::BoundingBox mWorldBorders;
};

} // namespace turboHikerSFML

#endif // TURBOHIKER_TRANSFORMATION_H
