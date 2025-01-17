//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_MYRENDERWINDOW_H
#define TURBOHIKER_MYRENDERWINDOW_H

#include "DrawableRenderer.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace turboHiker {
/**
 * Just a RenderWindow that also implements DrawableRenderer so that RenderComponents can call renderOnWindow()
 */
class MyRenderWindow : public sf::RenderWindow, public turboHiker::DrawableRenderer
{

public:

        /**
         * SimpleConstructor
         * See RenderWindow for specific parameter information
         */
        MyRenderWindow(const sf::VideoMode& mode, const sf::String& title, unsigned int style = sf::Style::Default,
                       const sf::ContextSettings& settings = sf::ContextSettings());

private:

        /**
         * Render the drawable onto the window
         * @param drawable: drawable to render
         */
        void renderOnWindow(const sf::Drawable& drawable) override;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_MYRENDERWINDOW_H
