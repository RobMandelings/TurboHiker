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

namespace turboHiker {

class RenderComponentSFML : public turboHiker::RenderComponent
{
public:
        explicit RenderComponentSFML(DrawableRenderer& windowDrawer);

        void renderOnWindow(const sf::Drawable& drawable) const;

        /**
         * If you want to change the scale of the drawings or overall sizes depending on if the view changed (for
         * example, if you want to apply zooming), implement this function.
         */
        virtual void onViewChange() const;

private:
        DrawableRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_RENDERCOMPONENTSFML_H