//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include <chrono>

namespace turboHikerLib {

class Game
{

public:
        /**
         * Starts and maintains the Game Loop
         */
        void run();

private:
        const std::chrono::milliseconds UPDATE_TIMESTEP;

        Game(std::chrono::milliseconds UPDATE_TIMESTEP);

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
};
} // namespace turboHikerLib