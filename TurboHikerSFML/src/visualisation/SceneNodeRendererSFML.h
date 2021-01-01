//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_SCENENODERENDERERSFML_H
#define TURBOHIKER_SCENENODERENDERERSFML_H

#include "DrawableRenderer.h"
#include "SceneNodeRenderer.h"

namespace turboHiker {
class WorldLocation;
}

namespace turboHikerSFML {

class SceneNodeRendererSFML : public turboHiker::SceneNodeRenderer
{
public:
        explicit SceneNodeRendererSFML(turboHiker::DrawableRenderer& windowDrawer);

        void renderOnWindow(const sf::Drawable& drawable) const;

private:
        turboHiker::DrawableRenderer& mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SCENENODERENDERERSFML_H