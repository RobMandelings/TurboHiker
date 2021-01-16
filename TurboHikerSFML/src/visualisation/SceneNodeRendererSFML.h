//
// Created by RobMa on 22/12/2020.
//

#pragma once

#include "DrawableRenderer.h"
#include "Renderer.h"

namespace turboHiker {
}

namespace turboHikerSFML {

/**
 * Renderer used to render a SceneNode using SFML
 */
class SceneNodeRendererSFML : public turboHiker::Renderer
{
public:

        /**
         * Simple constructor
         * @param drawableRenderer: the renderer to render the drawable
         */
        explicit SceneNodeRendererSFML(turboHiker::DrawableRenderer& drawableRenderer);

        /**
         * Render the given drawable onto the window
         * @param drawable: drawable to render
         */
        void renderOnWindow(const sf::Drawable& drawable) const;

private:

        /**
         * Used to render a drawable onto the window
         */
        turboHiker::DrawableRenderer& mDrawableRenderer;
};
} // namespace turboHikerSFML