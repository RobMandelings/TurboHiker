//
// Created by RobMa on 22/12/2020.
//

#include "SpriteRenderComponent.h"

#include <utility>
turboHiker::SpriteRenderComponent::SpriteRenderComponent(DrawableRenderer& windowDrawer, const sf::Sprite& sprite)
    : RenderComponentSFML(windowDrawer), mShape(std::make_unique<sf::Sprite>(sprite))
{
}
void turboHiker::SpriteRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                                   const turboHiker::Vector2d& currentWorldLocation)
{
        mShape->setPosition(float(currentWorldLocation.x), float(currentWorldLocation.y));
}

void turboHiker::SpriteRenderComponent::render() const { renderOnWindow(*mShape); }