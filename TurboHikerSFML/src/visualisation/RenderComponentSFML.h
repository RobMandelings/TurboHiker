//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_RENDERCOMPONENTSFML_H
#define TURBOHIKER_RENDERCOMPONENTSFML_H

#include "RenderComponent.h"
#include "WindowRenderer.h"

namespace turboHiker {
class WorldLocation;
}

namespace turboHikerSFML {

class RenderComponentSFML : public turboHiker::RenderComponent
{
public:
        explicit RenderComponentSFML(WindowRenderer& windowDrawer);

public:
        void renderOnWindow(sf::Sprite& drawable, const turboHiker::Vector2d& worldLocation) const;

        void drawOnWindow(sf::Shape& drawable, const turboHiker::Vector2d& worldLocation) const;

private:
        WindowRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H