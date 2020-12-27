//
// Created by RobMa on 23/12/2020.
//

#include "MyRenderWindow.h"

turboHiker::MyRenderWindow::MyRenderWindow(const sf::VideoMode& mode, const sf::String& title, unsigned int style,
                               const sf::ContextSettings& settings)
    : RenderWindow(mode, title, style, settings)
{
}
void turboHiker::MyRenderWindow::renderOnWindow(const sf::Drawable& drawable) {
        this->draw(drawable);
}