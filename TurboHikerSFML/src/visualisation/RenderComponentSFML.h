//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_RENDERCOMPONENTSFML_H
#define TURBOHIKER_RENDERCOMPONENTSFML_H

#include "WindowDrawer.h"
#include "turboHiker/ecs/components/RenderComponent.h"

namespace turboHiker {
class WorldLocation;
}

namespace turboHikerSFML {

class RenderComponentSFML : turboHiker::RenderComponent
{
public:
        explicit RenderComponentSFML(WindowDrawer& windowDrawer);

public:
        void drawOnWindow(const sf::Drawable& drawable, const turboHiker::WorldLocation& worldLocation) const;

private:
        WindowDrawer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H