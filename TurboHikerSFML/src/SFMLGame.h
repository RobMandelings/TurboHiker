//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHiker/Game.h"
#include "WindowHandler.h"

namespace turboHiker {
class World;
}

namespace turboHikerSFML {
class SFMLGame : public turboHiker::Game
{
private:
public:
        SFMLGame(const std::chrono::duration<double>& timePerFrame);
        void stopRunning() override;
        bool isRunning() const override;

private:
        void processEvents() override;
        void render() override;

        WindowHandler mWindowHandler;
};
}