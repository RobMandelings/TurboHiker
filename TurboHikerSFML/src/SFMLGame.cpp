//
// Created by Rob Mandelings on 12/12/2020.
//

#include "SFMLGame.h"
#include <SFML/Graphics/Text.hpp>

#include "BoundingBox.h"
#include "FontManager.h"
#include "Score.h"
#include "Transformation.h"
#include "World.h"

#include "SceneNodeFactorySFML.h"

using namespace turboHiker;
using namespace turboHiker;

SFMLGame::SFMLGame(const std::chrono::duration<double>& timePerFrame)
    : Game(timePerFrame, std::make_unique<turboHiker::World>(BoundingBox(0,0, 1000, 6000))),
      mWindow(sf::VideoMode(1000, 700), "TurboHiker")
{
        mWorld->setEntityFactory(std::make_unique<SceneNodeFactorySFML>(mWindow));
        Transformation::get().initialize(WindowSize(mWindow.getSize().x, mWindow.getSize().y),
                                         this->mWorld->getWorldBorders());
        Transformation::get().setWorldViewHeight(500);
        Transformation::get().setWorldViewCenterY(Transformation::get().getWorldView().getWorldViewHeight() / 2);
        mWorld->buildWorld(12);
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

        std::vector<sf::Text> generalTextsToDisplay;

        sf::Text text;
        text.setFont(arial);
        text.setCharacterSize(15);

        text.setString(std::string("Current Hike Status: ") +
                       (mWorld->getHikeStatus() == HikeStatus::BeforeHiking   ? "Not Started"
                        : mWorld->getHikeStatus() == HikeStatus::WhilstHiking ? "Hiking"
                                                                              : "Finished"));

        generalTextsToDisplay.push_back(text);

        text.setString("Player Speed: (X: " + std::to_string(mWorld->getPlayerHiker().getVelocity().x) +
                       ", Y: " + std::to_string(mWorld->getPlayerHiker().getVelocity().y) + ")");
        generalTextsToDisplay.push_back(text);

        text.setString("Player Location: (X: " + std::to_string(mWorld->getPlayerHiker().getLocation().x) +
                       ", Y: " + std::to_string(mWorld->getPlayerHiker().getLocation().y) + ")");
        generalTextsToDisplay.push_back(text);

        text.setString("Amount of competing hikers: " + std::to_string(mWorld->getAmountOfCompetingHikers()));
        generalTextsToDisplay.push_back(text);

        float yLocation = 2;
        for (sf::Text& currentTextToDisplay : generalTextsToDisplay) {

                currentTextToDisplay.setPosition(5, yLocation);
                yLocation += static_cast<float>(currentTextToDisplay.getCharacterSize());
                mWindow.draw(currentTextToDisplay);
        }

        std::vector<sf::Text> currentStatsToDisplay;

        text.setString("Live Score and Stats: ");
        currentStatsToDisplay.push_back(text);

        const Score& liveScore = mWorld->getScore();

        text.setString(
            "Hike duration: " +
            (mWorld->getHikeStatus() == HikeStatus::WhilstHiking || mWorld->getHikeStatus() == HikeStatus::AfterHiking
                 ? (std::to_string(liveScore.getHikeDuration().count()))
                 : "0") +
            " seconds");
        currentStatsToDisplay.push_back(text);

        text.setString("Hikers yelled at: " + std::to_string(liveScore.getHikersYelledAt()));
        currentStatsToDisplay.push_back(text);

        text.setString("Hikers collided with: " + std::to_string(liveScore.getAmountOfCollisions()));
        currentStatsToDisplay.push_back(text);

        text.setString("Reference point rate: " + std::to_string(liveScore.getBasePointRate()) + " in " +
                       std::to_string(liveScore.getReferenceDuration().count()) + " seconds");
        currentStatsToDisplay.push_back(text);

        text.setString("Current points: " + std::to_string(liveScore.getPointsAtFinish()));
        currentStatsToDisplay.push_back(text);

        text.setString("High scores: ");
        currentStatsToDisplay.push_back(text);

        const std::vector<Score>& highScores = mWorld->getHighScores().getHighScores();
        for (int currentHighScore = 0; currentHighScore < highScores.size(); currentHighScore++) {
                text.setString("High score " + std::to_string(currentHighScore + 1) + ": " +
                               std::to_string(highScores.at(currentHighScore).getPointsAtFinish()));
                currentStatsToDisplay.push_back(text);
        }

        float pointsYLocation = 2;
        for (sf::Text& currentTextToDisplay : currentStatsToDisplay) {

                currentTextToDisplay.setPosition(mWindow.getSize().x - currentTextToDisplay.getGlobalBounds().width - 5,
                                                 pointsYLocation);
                pointsYLocation += static_cast<float>(currentTextToDisplay.getCharacterSize());
                mWindow.draw(currentTextToDisplay);
        }
}
