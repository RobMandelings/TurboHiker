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
      mWindow(sf::VideoMode(700, 500), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<EntityFactorySFML>(mWindow));
        Transformation::get().initialize(WorldView(worldBorders.getWidth(), 10.0, Vector2d(worldBorders.getWidth() / 2, 25)),
                                         WindowSize(mWindow.getSize().x, mWindow.getSize().y), worldBorders);
        mWorld->buildWorld();
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

                        double newWorldViewWidth = double(event.size.width) / previousWindowSize.getWidth() *
                                                   Transformation::get().getWorldView().getWorldXSize();
                        double newWorldViewHeight = double(event.size.height) / previousWindowSize.getHeight() *
                                                    Transformation::get().getWorldView().getWorldYSize();

                        Transformation::get().getWorldView().setWorldViewCenter(Vector2d(
                            Transformation::get().getWorldView().getWorldViewCenter().x, newWorldViewHeight / 2));

                        // You can proportionally see more of the world now (proportionally to the pixels more you can
                        // see). Thus the distances between pixel mappings stay the same
                        Transformation::get().getWorldView().setWidth(newWorldViewWidth);
                        Transformation::get().getWorldView().setHeight(newWorldViewHeight);
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
