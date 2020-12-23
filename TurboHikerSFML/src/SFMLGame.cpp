//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

#include "EntityFactorySFML.h"

using namespace turboHikerSFML;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame) : Game(timePerFrame, std::make_unique<turboHiker::World>()), mWindowHandler()
{
        mWorld->setEntityFactory(std::make_unique<EntityFactorySFML>(mWindowHandler));
        mWorld->buildWorld();
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
