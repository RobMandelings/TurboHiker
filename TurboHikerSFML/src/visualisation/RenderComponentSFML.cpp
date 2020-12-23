//
// Created by RobMa on 22/12/2020.
//

#include "RenderComponentSFML.h"
#include "WorldLocation.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHikerSFML::RenderComponentSFML::RenderComponentSFML(WindowDrawer& windowDrawer) : mWindowDrawer(windowDrawer)
{
}

void turboHikerSFML::RenderComponentSFML::drawOnWindow(sf::Sprite& drawable, const Vector2d& worldLocation) const
{
        mWindowDrawer.drawOnWindow(drawable, worldLocation);
}