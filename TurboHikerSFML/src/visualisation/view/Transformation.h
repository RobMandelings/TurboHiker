//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include "BoundingBox.h"
#include "WindowSize.h"
#include "WorldView.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <mutex>
#include <utility>

namespace turboHiker {
class BoundingBox;
}

namespace turboHikerSFML {

// TODO implement scaling/zooming: draw the entities smaller or bigger depending on changes in view
class Transformation
{

public:
        Transformation(Transformation& other) = delete;

        void operator=(const Transformation&) = delete;

        static Transformation& get();

        void initialize(const WorldView& worldView, const WindowSize& windowSize,
                        const turboHiker::BoundingBox& worldBorders);

        WorldView& getWorldView() const;

        WindowSize& getWindowSize() const;

        sf::Vector2f convertWorldCoordinatesToPixelCoordinates(const turboHiker::Vector2d& worldCoordinates) const;

        /**
         * Converts the given worldCoordinates to its corresponding pixel values of the screen, assuming that these
         * world coordinates have already been translated by the center of view
         * @param worldCoordinates
         * @return
         */
        void scaleWorldCoordinatesToPixelCoordinates(sf::Vector2f& worldCoordinates) const;

        turboHiker::BoundingBox convertWorldBoundingBoxToVisualBoundingBox(
            const turboHiker::BoundingBox& worldBoundingBox) const;

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
