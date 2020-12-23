//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame, std::unique_ptr<turboHiker::World>& world)
    : Game(timePerFrame, world)
{
}

void SFMLGame::processInputEvents() {}
void SFMLGame::render() {}