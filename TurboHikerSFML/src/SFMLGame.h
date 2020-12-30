//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHiker/Game.h"

#include "MyRenderWindow.h"
#include "Player.h"

namespace turboHiker {
class World;
class EntityFactory;
}

namespace turboHiker {
class SFMLGame : public turboHiker::Game
{
private:
public:
        SFMLGame(const std::chrono::duration<double>& timePerFrame);
        void stopRunning() override;
        bool isRunning() const override;

private:
        void processInput() override;
        void render() override;

        // TODO add initializeWindow method

        turboHiker::MyRenderWindow mWindow;

        Player mPlayer;
};
}