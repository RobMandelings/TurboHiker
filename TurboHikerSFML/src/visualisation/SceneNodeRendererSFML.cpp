//
// Created by RobMa on 22/12/2020.
//

#include "SceneNodeRendererSFML.h"
#include "WorldLocation.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHikerSFML::SceneNodeRendererSFML::SceneNodeRendererSFML(DrawableRenderer& windowDrawer) : mWindowDrawer(windowDrawer) {}

void turboHikerSFML::SceneNodeRendererSFML::renderOnWindow(const sf::Drawable& drawable) const
{
        mWindowDrawer.renderOnWindow(drawable);
}