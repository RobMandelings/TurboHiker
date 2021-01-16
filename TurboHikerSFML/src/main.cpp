#include <SFML/Graphics.hpp>

#include "GameSFML.h"

#include "BoundingBox.h"
#include "SceneNodeFactorySFML.h"
#include "turboHiker/world/World.h"
#include <chrono>
#include <iostream>

using namespace turboHiker;

int main()
{

        GameSFML game(std::chrono::duration<double>(1 / 120.0));
        game.startRunning();

        return 0;
}