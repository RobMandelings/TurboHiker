//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

using namespace turboHikerSFML;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame, std::unique_ptr<turboHiker::World>& world)
    : Game(timePerFrame, world), mWindowHandler()
{
}

void SFMLGame::processEvents() { mWindowHandler.processEvents(); }
void SFMLGame::render()
{
        mWindowHandler.clearWindow();
        mWorld->draw();
        mWindowHandler.displayWindow();
}

void SFMLGame::stopRunning() { mWindowHandler.closeWindow(); }
bool SFMLGame::isRunning() const { return mWindowHandler.getWindow().isOpen(); }
