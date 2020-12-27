//
// Created by RobMa on 22/12/2020.
//

#include "RenderComponentSFML.h"
#include "WorldLocation.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHiker::RenderComponentSFML::RenderComponentSFML(DrawableRenderer& windowDrawer) : mWindowDrawer(windowDrawer) {}

void turboHiker::RenderComponentSFML::renderOnWindow(const sf::Drawable& drawable) const
{
        mWindowDrawer.renderOnWindow(drawable);
}

void turboHiker::RenderComponentSFML::onViewChange() const {
        // Do nothing by default
}
