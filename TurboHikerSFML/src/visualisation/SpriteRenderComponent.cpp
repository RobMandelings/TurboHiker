//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
void turboHikerSFML::SpriteRenderComponent::render(const turboHiker::Vector2d& worldLocation) const
{
        renderOnWindow(*mShape, worldLocation);
}
turboHikerSFML::SpriteRenderComponent::SpriteRenderComponent(WindowRenderer& windowDrawer, const sf::Sprite& sprite)
    : RenderComponentSFML(windowDrawer), mShape(std::make_unique<sf::Sprite>(sprite))
{
}