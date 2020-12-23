//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHiker/Game.h"

namespace turboHiker {
class World;
}

class SFMLGame : public turboHiker::Game
{
private:
public:
        SFMLGame(const std::chrono::duration<double>& timePerFrame, std::unique_ptr<turboHiker::World>& world);
private:
        void processInputEvents() override;
        void render() override;
};
