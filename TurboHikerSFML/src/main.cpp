#include <SFML/Graphics.hpp>

#include "SFMLGame.h"

#include "World.h"
#include "EntityFactorySFML.h"
#include "WindowHandler.h"
#include <iostream>
#include <chrono>

using namespace turboHikerSFML;

int main()
{

        std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>();

        std::unique_ptr<EntityFactorySFML> entityFactory = std::make_unique<EntityFactorySFML>();
        std::unique_ptr<turboHiker::World> world = std::make_unique<turboHiker::World>(std::move(entityFactory));

        using namespace std::chrono_literals;
        SFMLGame game(std::chrono::duration<double>(1 / 3.0), world);
        game.startRunning();

        return 0;
}