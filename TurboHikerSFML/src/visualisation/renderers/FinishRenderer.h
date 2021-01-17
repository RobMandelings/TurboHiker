//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_FINISHRENDERER_H
#define TURBOHIKER_FINISHRENDERER_H

#include "SceneNodeRendererSFML.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "Finish.h"

namespace turboHikerSFML {

/**
 * Renderer used to render the finish
 */
class FinishRenderer : public turboHikerSFML::SceneNodeRendererSFML<turboHiker::Finish>
{

public:
        /**
         * Simple constructor
         * @param drawableRenderer: the renderer that is used to render the finish
         * @param dimensions: dimensions of the finish
         */
        FinishRenderer(turboHiker::DrawableRenderer& drawableRenderer, const sf::Vector2f& dimensions);

private:
        /**
         * See base class
         */
        std::unique_ptr<Renderer<turboHiker::SceneNode>> clone() const override;

        /**
         * See Renderer
         */
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        /**
         * See Renderer
         */
        void render() const override;

private:
        /**
         * Shape representing the finish
         */
        sf::RectangleShape mFinishShape;

        /**
         * Creates the finish shape
         * @param dimensions: the dimensions in pixels
         * @return the created shape for the finish
         */
        sf::RectangleShape createFinish(const sf::Vector2f& dimensions);
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_FINISHRENDERER_H
