//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_WINDOWHANDLER_H
#define TURBOHIKER_WINDOWHANDLER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <interfaces/WindowDrawer.h>

#include <SFML/Graphics/Sprite.hpp>
#include <memory>

namespace turboHikerSFML {
// Maybe its better to extend from RenderWindow
class WindowHandler : WindowDrawer
{
public:
        WindowHandler();

        void clearWindow();

        void displayWindow();

        void processEvents();

        void closeWindow();

        void drawOnWindow(sf::Sprite& sprite, const turboHiker::Vector2d& worldLocation) override;

        const sf::RenderWindow& getWindow() const;

private:

        sf::RenderWindow mWindow;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_WINDOWHANDLER_H
