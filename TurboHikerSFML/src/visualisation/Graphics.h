//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_GRAPHICS_H
#define TURBOHIKER_GRAPHICS_H

#include <interfaces/WindowDrawer.h>

namespace turboHikerSFML {
class Graphics : public WindowDrawer
{

public:
        void drawOnWindow(const sf::Drawable& drawable, const turboHiker::Vector2d& worldLocation) override;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_GRAPHICS_H
