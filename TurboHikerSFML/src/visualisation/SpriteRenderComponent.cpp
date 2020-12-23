//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
void turboHikerSFML::SpriteRenderComponent::draw(const turboHiker::WorldLocation& worldLocation) const {
        drawOnWindow(mSprite, worldLocation); }
turboHikerSFML::SpriteRenderComponent::SpriteRenderComponent(const turboHiker::WorldLocation& worldPosition,
                                                             turboHikerSFML::WindowDrawer& windowDrawer,
                                                             sf::Sprite mSprite)
    : RenderComponentSFML(windowDrawer), mSprite(std::move(mSprite))
{
}