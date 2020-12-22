//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_RENDERCOMPONENTSFML_H
#define TURBOHIKER_RENDERCOMPONENTSFML_H

#include "turboHiker/ecs/components/RenderComponent.h"
#include "WindowDrawer.h"

namespace turboHikerSFML {
class RenderComponentSFML : turboHiker::RenderComponent
{
public:
        RenderComponentSFML(const turboHiker::WorldLocation& worldPosition, WindowDrawer& windowDrawer);

public:

        void drawOnWindow(const sf::Drawable& drawable) const;

private:
        WindowDrawer& mWindowDrawer;
};
}

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H