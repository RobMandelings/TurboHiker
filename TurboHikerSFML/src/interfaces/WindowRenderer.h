//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_WINDOWDRAWER_H
#define TURBOHIKER_WINDOWDRAWER_H

#endif // TURBOHIKER_WINDOWDRAWER_H

namespace sf {
class Drawable;
class Sprite;
class Shape;
}

namespace turboHiker {
class Vector2d;
}

namespace turboHikerSFML {

class WindowRenderer
{

public:
        /** Draws an SFML Drawable Object on the window */
        virtual void renderOnWindow(sf::Sprite& drawable) = 0;

        virtual void renderOnWindow(sf::Shape& drawable) = 0;
};
} // namespace turboHikerSFML