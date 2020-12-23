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

void turboHikerSFML::RenderComponentSFML::renderOnWindow(sf::Sprite& drawable, const Vector2d& worldLocation) const
{
        mWindowDrawer.renderOnWindow(drawable, worldLocation);
}

void turboHikerSFML::RenderComponentSFML::drawOnWindow(sf::Shape& drawable, const Vector2d& worldLocation) const
{
        mWindowDrawer.renderOnWindow(drawable, worldLocation);
}