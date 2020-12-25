//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include "WorldView.h"
#include "WindowSize.h"

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

class Transformation
{

public:
        Transformation(Transformation& other) = delete;

        void operator=(const Transformation&) = delete;

        static const Transformation& get();

        void initialize(const WorldView& worldView, const WindowSize& windowSize);

        WorldView& getWorldView() const;

        WindowSize& getWindowSize() const;

        sf::Vector2f convertWorldCoordinatesToPixelValues(const turboHiker::Vector2d& worldCoordinates) const;

        sf::FloatRect convertWorldBoundingBoxToVisualBoundingBox(const turboHiker::BoundingBox& worldBoundingBox) const;

        turboHiker::BoundingBox convertVisualBoundingBoxToWorldBoundingBox(
            const sf::FloatRect& visualBoundingBox) const;

private:
        explicit Transformation();

private:
        static Transformation* mInstance;

        static std::mutex mMutex;

        bool initialized() const;

        std::unique_ptr<WorldView> mWorldView;

        std::unique_ptr<WindowSize> mWindowSize;
};

std::mutex Transformation::mMutex;

} // namespace turboHikerSFML

#endif // TURBOHIKER_TRANSFORMATION_H
