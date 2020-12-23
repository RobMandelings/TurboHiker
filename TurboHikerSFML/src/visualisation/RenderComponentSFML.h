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

        void renderOnWindow(const sf::Drawable& drawable) const;

private:
        WindowRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H