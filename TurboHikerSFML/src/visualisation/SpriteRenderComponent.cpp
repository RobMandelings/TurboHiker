//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
void turboHikerSFML::SpriteRenderComponent::draw() const { drawOnWindow(mSprite); }
turboHikerSFML::SpriteRenderComponent::SpriteRenderComponent(const turboHiker::WorldPosition& worldPosition,
                                                             turboHikerSFML::WindowDrawer& windowDrawer,
                                                             sf::Sprite mSprite)
    : RenderComponentSFML(worldPosition, windowDrawer), mSprite(std::move(mSprite))
{
}