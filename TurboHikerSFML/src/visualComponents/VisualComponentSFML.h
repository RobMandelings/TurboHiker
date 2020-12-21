//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_VISUALCOMPONENTSFML_H
#define TURBOHIKER_VISUALCOMPONENTSFML_H

#include <SFML/Graphics/Drawable.hpp>
#include <memory>

#include "turboHiker/abstractVisuals/VisualComponent.h"

namespace turboHikerSFML {
class WindowDrawer;
}

namespace turboHikerSFML {
class VisualComponentSFML : private turboHiker::VisualComponent, private sf::Drawable
{

        // TODO check: should this method be defined public as well or is it enough for this method to be private and
        // the parent classes' method not?

        /**
         * Draw method called by the GameObject that implements it.
         * Considered final as it may not be overridden by inherited classes
         */
        void draw(const turboHiker::Vector2d& worldLocation) const final;

private:
        const std::shared_ptr<WindowDrawer> mWindowDrawer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_VISUALCOMPONENTSFML_H
