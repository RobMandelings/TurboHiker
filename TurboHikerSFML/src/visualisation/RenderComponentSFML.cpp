//
// Created by RobMa on 22/12/2020.
//

#include "RenderComponentSFML.h"
#include "turboHiker/ecs/components/modules/WorldLocation.h"
#include <SFML/Graphics/Drawable.hpp>

using namespace turboHiker;

turboHikerSFML::RenderComponentSFML::RenderComponentSFML(WindowDrawer& windowDrawer) : mWindowDrawer(windowDrawer)
{
}

void turboHikerSFML::RenderComponentSFML::drawOnWindow(const sf::Drawable& drawable,
                                                       const WorldLocation& worldLocation) const
{
        mWindowDrawer.drawOnWindow(drawable, worldLocation.getVectorPositionRef());
}