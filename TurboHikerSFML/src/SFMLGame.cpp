//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

#include "BoundingBox.h"
#include "Transformation.h"
#include "World.h"

#include "EntityFactorySFML.h"

using namespace turboHiker;
using namespace turboHiker;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame)
    : Game(timePerFrame, std::make_unique<turboHiker::World>(15, 50, 1000)),
      mWindow(sf::VideoMode(1000, 700), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<EntityFactorySFML>(mWindow));
        Transformation::get().initialize(WindowSize(mWindow.getSize().x, mWindow.getSize().y), this->mWorld->getWorldBorders());
        Transformation::get().setWorldViewWidth(this->mWorld->getWorldBorders().getWidth());
        mWorld->buildWorld(15);
}

void SFMLGame::processInput()
{
        CommandQueue& commands = mWorld->getCommandQueue();

        sf::Event event{};
        while (mWindow.pollEvent(event)) {
                mPlayer.handleEvent(event, commands);

                if (event.type == sf::Event::Closed) {
                        mWindow.close();
                } else if (event.type == sf::Event::Resized) {

                        // This makes it so that you can see more of the actual game, instead of stretching / squeezing
                        // the sprites

                        // Let the drawings not be squeezed / stretched
                        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                        mWindow.setView(sf::View(visibleArea));
                        const WindowSize& previousWindowSize = Transformation::get().getWindowSize();

                        Transformation::get().setWindowSize(WindowSize(int(event.size.width), int(event.size.height)));
                }
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
