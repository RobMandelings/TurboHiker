//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHikerLib/Game.h"

class SFMLGame : public turboHikerLib::Game
{
public:
        SFMLGame(const std::chrono::seconds& timePerFrame);
private:
        void processInputEvents() override;
        void render() override;
};