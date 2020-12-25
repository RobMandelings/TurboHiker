//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

#include "Transformation.h"
#include "BoundingBox.h"
#include "World.h"

#include "EntityFactorySFML.h"

using namespace turboHiker;
using namespace turboHikerSFML;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame, const BoundingBox& worldBorders)
    : Game(timePerFrame, std::make_unique<turboHiker::World>(worldBorders)), mWindow(sf::VideoMode(1000, 500), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<EntityFactorySFML>(mWindow));
        mWorld->buildWorld();
        Transformation::get().initialize(WorldView(100.0, 100.0, Vector2d(20, 20)),
                                         WindowSize(mWindow.getSize().x, mWindow.getSize().y), worldBorders);
}

void SFMLGame::processInput()
{
        CommandQueue& commands = mWorld->getCommandQueue();

        sf::Event event{};
        while (mWindow.pollEvent(event)) {
                mPlayer.handleEvent(event, commands);

                if (event.type == sf::Event::Closed)
                        mWindow.close();
        }

        mPlayer.handleRealtimeInput(commands);
}
void SFMLGame::render()
{
        mWindow.clear();
        mWorld->render();
        mWindow.display();
}

void SFMLGame::stopRunning() { mWindow.close(); }
bool SFMLGame::isRunning() const { return mWindow.isOpen(); }
