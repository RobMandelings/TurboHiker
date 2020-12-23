#include <SFML/Graphics.hpp>

#include "SFMLGame.h"

#include "World.h"
#include "EntityFactorySFML.h"
#include <iostream>
#include <chrono>

using namespace turboHikerSFML;

int main()
{
        /**sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        window.setVerticalSyncEnabled(true);
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);*/

        std::unique_ptr<EntityFactorySFML> entityFactory = std::make_unique<EntityFactorySFML>();

        std::unique_ptr<turboHiker::World> world = std::make_unique<turboHiker::World>(std::move(entityFactory));

        using namespace std::chrono_literals;
        SFMLGame game(std::chrono::duration<double>(1 / 3.0), world);
        game.startRunning();

//        while (window.isOpen()) {
//                sf::Event event{};
//                while (window.pollEvent(event)) {
//                        std::cout << event.type << std::endl;
//                        switch (event.type) {
//                        case sf::Event::Closed:
//                                window.close();
//                                break;
//                        default:
//                                break;
//                        }
//                }
//
//                window.clear();
//                window.draw(shape);
//                window.display();
//        }

        return 0;
}