//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_WINDOWDRAWER_H
#define TURBOHIKER_WINDOWDRAWER_H

#endif // TURBOHIKER_WINDOWDRAWER_H

namespace sf {
class Drawable;
}

namespace turboHiker {
class Vector2d;
}

namespace turboHikerSFML {

class WindowDrawer
{

public:
        /** Draws an SFML Drawable Object on the window */
        virtual void drawOnWindow(const sf::Drawable& drawable, const turboHiker::Vector2d& worldLocation) = 0;
};
} // namespace turboHikerSFML