//
// Created by RobMa on 22/12/2020.
//

#include "SceneNodeRendererSFML.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHikerSFML::SceneNodeRendererSFML::SceneNodeRendererSFML(DrawableRenderer& drawableRenderer) : mDrawableRenderer(drawableRenderer) {}

void turboHikerSFML::SceneNodeRendererSFML::renderOnWindow(const sf::Drawable& drawable) const
{
        mDrawableRenderer.renderOnWindow(drawable);
}