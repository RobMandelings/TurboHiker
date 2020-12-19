//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHiker/Game.h"

class SFMLGame : public turboHiker::Game
{
private:
public:
        SFMLGame(const std::chrono::duration<double>& timePerFrame);
private:
        void processInputEvents() override;
        void render() override;
};
