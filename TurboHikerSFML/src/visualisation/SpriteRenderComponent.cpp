//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
void turboHikerSFML::SpriteRenderComponent::draw(const turboHiker::Vector2d& worldLocation) const
{
        drawOnWindow(*mSprite, worldLocation);
}
turboHikerSFML::SpriteRenderComponent::SpriteRenderComponent(const turboHiker::WorldLocation& worldPosition,
                                                             turboHikerSFML::WindowDrawer& windowDrawer,
                                                             const sf::Sprite& sprite)
    : RenderComponentSFML(windowDrawer), mSprite(std::make_unique<sf::Sprite>(sprite))
{
}