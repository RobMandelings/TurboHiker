//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_RENDERCOMPONENTSFML_H
#define TURBOHIKER_RENDERCOMPONENTSFML_H

#include "DrawableRenderer.h"
#include "RenderComponent.h"

namespace turboHiker {
class WorldLocation;
}

namespace turboHikerSFML {

class RenderComponentSFML : public turboHiker::RenderComponent
{
public:
        explicit RenderComponentSFML(DrawableRenderer& windowDrawer);

        void renderOnWindow(const sf::Drawable& drawable) const;

private:
        DrawableRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H