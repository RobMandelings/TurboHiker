//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include <chrono>

namespace turboHiker {

class Game
{

public:

        Game(std::chrono::nanoseconds timePerFrame);

        /**
         * Starts and maintains the Game Loop
         */
        void startRunning();

        /**
         * Stops the game in a proper manner
         */
        void stopRunning();

        /**
         * Checks whether the game is running or not
         * @return true if the game is currently running
         */
        bool isRunning() const;

        /**
         * The logic framerate of the game (how many seconds per logic update)
         * @return
         */
        const std::chrono::nanoseconds& getTimePerFrame() const;

        // TODO add pause functionality

private:

        /**
         * Process input events such as user input
         */
        virtual void processInputEvents() = 0;

        /**
         * Updates the game by the given timestep
         */
        void update();

        /**
         * Renders the game (window, world, overlays,...)
         */
        virtual void render() = 0;

private:

        std::chrono::nanoseconds m_timePerFrame;

        bool m_isRunning;
};
} // namespace turboHiker