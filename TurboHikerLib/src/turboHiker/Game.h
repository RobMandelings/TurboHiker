//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include <chrono>
#include <memory>

#include "BoundingBox.h"
#include "LiveScore.h"

namespace turboHiker {

class World;

class Game
{

public:
        Game(std::chrono::duration<double> timePerFrame, std::unique_ptr<World> world);

        /**
         * Starts and maintains the Game Loop
         */
        void startRunning();

        /**
         * Stops the game in a proper manner
         */
        virtual void stopRunning() = 0;

        /**
         * Checks whether the game is running or not
         * @return true if the game is currently running
         */
        virtual bool isRunning() const = 0;

        /**
         * The logic framerate of the game (how many seconds per logic update)
         * @return
         */
        const std::chrono::duration<double>& getTimeStep() const;

        // TODO add pause functionality

protected:

        /**
         * Renders the game (window, world, overlays,...)
         */
        virtual void render() = 0;

        /**
         * Process input events such as user input
         */
        virtual void processInput() = 0;

protected:

        std::unique_ptr<World> mWorld;

private:

        /**
         * Updates the game by the given timestep
         */
        void update();

private:

        std::chrono::duration<double> m_timePerFrame;
};
} // namespace turboHiker