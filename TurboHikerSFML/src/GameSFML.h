//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include "turboHiker/Game.h"

#include "MyRenderWindow.h"
#include "Player.h"

namespace turboHiker {
class World;
class SceneNodeFactory;
} // namespace turboHiker

namespace turboHiker {

/**
 * SFML Implementation of the Game. Handles aspects that are not related to game logic only as well
 */
class GameSFML : public turboHiker::Game
{
private:
public:
        /**
         * Simple constructor
         * @param timePerFrame: by how much time a world update should be
         */
        explicit GameSFML(const std::chrono::duration<double>& timePerFrame);

        /**
         * Stop running the game
         */
        void stopRunning() override;

        /**
         * Checks whether or not the game is still running
         * @return true if this is the case, false if not
         */
        bool isRunning() const override;

private:
        /**
         * Process any input events that may have occurred (such as key presses, mouse clicks,...)
         */
        void processInput() override;

        /**
         * Render the game
         */
        void render() override;

        /**
         * Draws an overlay of all current statistics (Hike status, Positions,...)
         */
        void drawStatsOverlay();

        /**
         * The window used to render the game in
         */
        turboHiker::MyRenderWindow mWindow;

        /**
         * The player which handles the adding of new commands if necessary, based on input
         */
        Player mPlayer;
};
} // namespace turboHiker