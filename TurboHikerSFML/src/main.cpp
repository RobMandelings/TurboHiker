#include <SFML/Graphics.hpp>

#include "SFMLGame.h"

#include "BoundingBox.h"
#include "EntityFactorySFML.h"
#include "turboHiker/world/World.h"
#include <chrono>
#include <iostream>

using namespace turboHiker;

int main()
{


        SFMLGame game(std::chrono::duration<double>(1 / 120.0));
        game.startRunning();

        return 0;
}