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
        SpriteRenderComponent(const turboHiker::WorldPosition& worldPosition, WindowDrawer& windowDrawer,
                              sf::Sprite  mSprite);

        void draw() const final;

private:

        sf::Sprite mSprite;

};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SPRITERENDERCOMPONENT_H
