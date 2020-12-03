#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        window.setVerticalSyncEnabled(true);
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen()) {
                sf::Event event{};
                while (window.pollEvent(event)) {
                        std::cout << event.type << std::endl;
                        switch (event.type) {
                        case sf::Event::Closed:
                                window.close();
                                break;
                        default:
                                break;
                        }
                }

                window.clear();
                window.draw(shape);
                window.display();
        }

        return 0;
}