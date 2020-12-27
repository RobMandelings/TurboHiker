//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_SPRITERENDERCOMPONENT_H
#define TURBOHIKER_SPRITERENDERCOMPONENT_H

#include "RenderComponentSFML.h"
#include <SFML/Graphics/Sprite.hpp>

namespace turboHiker {
class SpriteRenderComponent : RenderComponentSFML
{

public:
        SpriteRenderComponent(DrawableRenderer& windowDrawer, const sf::Sprite& sprite);

private:
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;
public:
        void render() const final;

private:

        std::unique_ptr<sf::Sprite> mShape;

};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SPRITERENDERCOMPONENT_H
