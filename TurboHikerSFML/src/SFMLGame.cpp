//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"

#include "BoundingBox.h"
#include "Transformation.h"
#include "World.h"

#include "EntityFactorySFML.h"

using namespace turboHiker;
using namespace turboHikerSFML;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame, const BoundingBox& worldBorders)
    : Game(timePerFrame, std::make_unique<turboHiker::World>(worldBorders)),
      mWindow(sf::VideoMode(500, 500), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<EntityFactorySFML>(mWindow));
        mWorld->buildWorld();
        Transformation::get().initialize(WorldView(50.0, 50.0, Vector2d(25, 25)),
                                         WindowSize(mWindow.getSize().x, mWindow.getSize().y), worldBorders);
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

                        std::cout << mWindow.getPosition().x << std::endl;

                        double newWorldViewWidth = double(event.size.width) / previousWindowSize.getWidth() *
                                                   Transformation::get().getWorldView().getWorldXSize();
                        double newWorldViewHeight = double(event.size.height) / previousWindowSize.getHeight() *
                                                    Transformation::get().getWorldView().getWorldYSize();

                        Transformation::get().getWorldView().setWorldXSize(newWorldViewWidth);
                        Transformation::get().getWorldView().setWorldYSize(newWorldViewHeight);
                        // Change the window size in the transformation singleton so the conversion to pixels is altered
                        // as well
                        Transformation::get().getWindowSize().setWidth(int(event.size.width));
                        Transformation::get().getWindowSize().setHeight(int(event.size.height));
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
