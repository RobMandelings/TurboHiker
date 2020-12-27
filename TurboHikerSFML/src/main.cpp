#include <SFML/Graphics.hpp>

#include "SFMLGame.h"

#include "World.h"
#include "BoundingBox.h"
#include "EntityFactorySFML.h"
#include <iostream>
#include <chrono>

using namespace turboHikerSFML;

int main()
{


        SFMLGame game(std::chrono::duration<double>(1 / 120.0), turboHiker::BoundingBox(0, 0, 100, 200));
        game.startRunning();

        return 0;
}