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
} // namespace turboHiker

namespace turboHikerSFML {

// TODO resize shape depending on the current viewHeight and width.
/**
 * Renders a Hiker
 */
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

        /**
         * See Renderer
         */
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        /**
         * See Renderer
         */
        void render() const final;

        /**
         * Clones the renderer
         */
        std::unique_ptr<Renderer> clone() const override;

private:
        sf::CircleShape mHikerShape;
        turboHikerSFML::Color mCurrentColor;

        bool goingDown;
        double mSpeed;
        double summedDt;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKERRENDERER_H
