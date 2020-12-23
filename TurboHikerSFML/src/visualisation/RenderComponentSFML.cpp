//
// Created by RobMa on 22/12/2020.
//

#include "RenderComponentSFML.h"
#include "WorldLocation.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHikerSFML::RenderComponentSFML::RenderComponentSFML(WindowRenderer& windowDrawer) : mWindowDrawer(windowDrawer)
{
}

void turboHikerSFML::RenderComponentSFML::renderOnWindow(sf::Sprite& drawable) const
{
        mWindowDrawer.renderOnWindow(drawable);
}

void turboHikerSFML::RenderComponentSFML::drawOnWindow(sf::Shape& drawable) const
{
        mWindowDrawer.renderOnWindow(drawable);
}