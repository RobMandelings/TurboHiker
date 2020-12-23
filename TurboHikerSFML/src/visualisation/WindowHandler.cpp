//
// Created by RobMa on 23/12/2020.
//

#include "WindowHandler.h"
#include <SFML/Window/Event.hpp>

#include "WorldLocation.h"


turboHikerSFML::WindowHandler::WindowHandler() : mWindow(sf::VideoMode(200, 200), "SFML works!")
{
        mWindow.setVerticalSyncEnabled(true);
}

void turboHikerSFML::WindowHandler::clearWindow() {
        mWindow.clear();
}
void turboHikerSFML::WindowHandler::displayWindow() {
        mWindow.display();
}

void turboHikerSFML::WindowHandler::closeWindow() {
        mWindow.close();
}

void turboHikerSFML::WindowHandler::processEvents() {

        sf::Event event{};
        while (mWindow.pollEvent(event))
        {
                switch (event.type)
                {
                case sf::Event::KeyPressed:
                        //handlePlayerInput(event.key.code, true);
                        break;

                case sf::Event::KeyReleased:
                        //handlePlayerInput(event.key.code, false);
                        break;

                case sf::Event::Closed:
                        mWindow.close();
                        break;
                }
        }
}

void turboHikerSFML::WindowHandler::drawOnWindow(sf::Sprite& sprite, const turboHiker::Vector2d& worldLocation)
{
        sprite.setPosition(float(worldLocation.x), float(worldLocation.y));
        mWindow.draw(sprite);
}
const sf::RenderWindow& turboHikerSFML::WindowHandler::getWindow() const { return mWindow; }