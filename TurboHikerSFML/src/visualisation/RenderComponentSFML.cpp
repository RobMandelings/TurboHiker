//
// Created by RobMa on 22/12/2020.
//

#include "RenderComponentSFML.h"
#include "turboHiker/ecs/modules/WorldPosition.h"
#include <SFML/Graphics/Drawable.hpp>

void turboHikerSFML::RenderComponentSFML::drawOnWindow(const sf::Drawable& drawable) const
{
        mWindowDrawer.drawOnWindow(drawable, mWorldPosition.getVectorPositionRef());
}

turboHikerSFML::RenderComponentSFML::RenderComponentSFML(const turboHiker::WorldLocation& worldPosition,
                                                         turboHikerSFML::WindowDrawer& windowDrawer)
    : RenderComponent(worldPosition), mWindowDrawer(windowDrawer)
{
}