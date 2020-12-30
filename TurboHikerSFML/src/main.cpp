#include <SFML/Graphics.hpp>

#include "SFMLGame.h"

#include "World.h"
#include "BoundingBox.h"
#include "EntityFactorySFML.h"
#include <iostream>
#include <chrono>

using namespace turboHiker;

int main()
{


        SFMLGame game(std::chrono::duration<double>(1 / 120.0));
        game.startRunning();

        return 0;
}