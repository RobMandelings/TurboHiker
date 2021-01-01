//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKERRENDERER_H
#define TURBOHIKER_HIKERRENDERER_H

#include "Color.h"
#include "SceneNodeRendererSFML.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <memory>

namespace turboHiker {
class Vector2d;
class WorldLocation;
} // namespace turboHiker

namespace turboHikerSFML {

// TODO rezie shape depending on the current viewHeight and width.
class HikerRenderer : public turboHikerSFML::SceneNodeRendererSFML
{

public:
        /**
         * Constructor for the Render Component of a Hiker.
         * @param windowRenderer
         * @param animationSpeed
         * @param size: the size in pixels (radius of the circle)
         */
        HikerRenderer(turboHiker::DrawableRenderer& windowRenderer, double animationSpeed, float size, sf::Color color);

        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        void render() const final;

        std::unique_ptr<SceneNodeRenderer> clone() override;

private:
        sf::CircleShape mHikerShape;
        turboHikerSFML::Color mCurrentColor;

        bool goingDown;
        double mSpeed;
        double summedDt;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKERRENDERER_H
