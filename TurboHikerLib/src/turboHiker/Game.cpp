//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Game.h"

#include "Clock.h"
#include <cassert>
#include <iostream>
#include <thread>

turboHiker::Game::Game(std::chrono::duration<double> timePerFrame, std::unique_ptr<World> world)
    : m_timePerFrame(timePerFrame), mWorld(std::move(world))
{
}

/**
 * Uses fixed timestep on to maintain a steady framerate for logic updates. The framerate may be more / less laggy
 * depending on your system
 */
void turboHiker::Game::startRunning()
{

        turboHiker::Clock clock2;
        turboHiker::Clock clock;
        std::chrono::duration<double> timeSinceLastUpdate = std::chrono::nanoseconds(0);

        // TODO Set max framerate (optionally) as well (For example: max 60FPS)
        while (isRunning()) {
                processEvents();
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > getTimeStep()) {
                        timeSinceLastUpdate -= getTimeStep();

                        processEvents();
                        update();
                }

                render();
        }
}

void turboHiker::Game::update() { mWorld->update(getTimeStep()); }
const std::chrono::duration<double>& turboHiker::Game::getTimeStep() const { return m_timePerFrame; }
