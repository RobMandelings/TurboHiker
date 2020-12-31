//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKERRENDERCOMPONENT_H
#define TURBOHIKER_HIKERRENDERCOMPONENT_H

#include "Color.h"
#include "RenderComponentSFML.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <memory>

namespace turboHiker {
class Vector2d;
class WorldLocation;
} // namespace turboHiker

namespace turboHiker {

// TODO rezie shape depending on the current viewHeight and width.
class HikerRenderComponent : public RenderComponentSFML
{

public:
        /**
         * Constructor for the Render Component of a Hiker.
         * @param windowRenderer
         * @param animationSpeed
         * @param size: the size in pixels (radius of the circle)
         */
        HikerRenderComponent(DrawableRenderer& windowRenderer, double animationSpeed, float size, sf::Color color);

        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        void render() const final;

        std::unique_ptr<RenderComponent> clone() override;

private:
        sf::CircleShape mHikerShape;
        turboHikerSFML::Color mCurrentColor;

        bool goingDown;
        double mSpeed;
        double summedDt;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKERRENDERCOMPONENT_H
