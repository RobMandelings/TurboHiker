//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
void turboHikerSFML::SpriteRenderComponent::draw(const turboHiker::Vector2d& worldLocation) const
{
        drawOnWindow(*mShape, worldLocation);
}
turboHikerSFML::SpriteRenderComponent::SpriteRenderComponent(WindowDrawer& windowDrawer, const sf::Sprite& sprite)
    : RenderComponentSFML(windowDrawer), mShape(std::make_unique<sf::Sprite>(sprite))
{
}