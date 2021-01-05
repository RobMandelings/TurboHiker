//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"
#include <SFML/Graphics/Text.hpp>

#include "BoundingBox.h"
#include "FontManager.h"
#include "Transformation.h"
#include "turboHiker/world/World.h"

#include "SceneNodeFactorySFML.h"

using namespace turboHiker;
using namespace turboHiker;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame)
    : Game(timePerFrame, std::make_unique<turboHiker::World>(4, 50, 10000)),
      mWindow(sf::VideoMode(1000, 700), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<SceneNodeFactorySFML>(mWindow));
        Transformation::get().initialize(WindowSize(mWindow.getSize().x, mWindow.getSize().y),
                                         this->mWorld->getWorldBorders());
        // Transformation::get().setWorldViewWidth(this->mWorld->getWorldBorders().getWidth());
        Transformation::get().setWorldViewWidth(this->mWorld->getWorldBorders().getWidth());
        Transformation::get().setWorldViewCenterY(Transformation::get().getWorldView().getWorldViewHeight() / 2);
        mWorld->buildWorld(4);
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
                        Transformation::get().setWorldViewCenterY(
                            Transformation::get().getWorldView().getWorldViewHeight() / 2);
                }
        }

        mPlayer.handleRealtimeInput(commands);
}
void SFMLGame::render()
{
        mWindow.clear();
        mWorld->render();
        drawStatsOverlay();

        mWindow.display();
}

void SFMLGame::stopRunning() { mWindow.close(); }
bool SFMLGame::isRunning() const { return mWindow.isOpen(); }

void SFMLGame::drawStatsOverlay()
{

        const sf::Font& arial = FontManager::get().getFont(Font::ARIAL);

        std::vector<sf::Text> textsToDisplay;

        sf::Text text;
        text.setFont(arial);
        text.setCharacterSize(15);

        text.setString(mWorld->getHikeStatus() == HikeStatus::BeforeHiking   ? "Not Started"
                                 : mWorld->getHikeStatus() == HikeStatus::WhilstHiking ? "Hiking"
                                                                                       : "Finished");

        text.setString("Current Hike Status: " + text.getString());
        textsToDisplay.push_back(text);

        text.setString("Player Speed: (X: " + std::to_string(mWorld->getPlayerHiker().getVelocity().x) + ", Y: " + std::to_string(mWorld->getPlayerHiker().getVelocity().y) + ")");
        textsToDisplay.push_back(text);

        text.setString("Player Location: (X: " + std::to_string(mWorld->getPlayerHiker().getLocation().x) + ", Y: " + std::to_string(mWorld->getPlayerHiker().getLocation().y) + ")");
        textsToDisplay.push_back(text);

        text.setString("Amount of competing hikers: " + std::to_string(mWorld->getAmountOfCompetingHikers()));
        textsToDisplay.push_back(text);

        float yLocation = 2;
        for (sf::Text& currentTextToDisplay : textsToDisplay) {

                currentTextToDisplay.setPosition(5, yLocation);
                yLocation += static_cast<float>(currentTextToDisplay.getCharacterSize());
                mWindow.draw(currentTextToDisplay);

        }
}
