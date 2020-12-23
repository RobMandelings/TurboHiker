//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_SPRITERENDERCOMPONENT_H
#define TURBOHIKER_SPRITERENDERCOMPONENT_H

#include "RenderComponentSFML.h"
#include <SFML/Graphics/Sprite.hpp>

namespace turboHikerSFML {
class SpriteRenderComponent : RenderComponentSFML
{

public:
        SpriteRenderComponent(const turboHiker::WorldLocation& worldPosition, WindowDrawer& windowDrawer,
                              sf::Sprite  mSprite);

        void draw(const turboHiker::Vector2d& worldLocation) const final;

private:

        sf::Sprite mSprite;

};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SPRITERENDERCOMPONENT_H
