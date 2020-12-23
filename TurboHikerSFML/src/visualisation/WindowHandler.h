//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_WINDOWHANDLER_H
#define TURBOHIKER_WINDOWHANDLER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <interfaces/WindowRenderer.h>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

namespace turboHikerSFML {
// Maybe its better to extend from RenderWindow
class WindowHandler : public WindowRenderer
{
public:
        WindowHandler();

        void clearWindow();

        void displayWindow();

        void processEvents();

        void closeWindow();

        void renderOnWindow(const sf::Drawable& drawable) override;

public:
        const sf::RenderWindow& getWindow() const;

private:

        sf::RenderWindow mWindow;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_WINDOWHANDLER_H
