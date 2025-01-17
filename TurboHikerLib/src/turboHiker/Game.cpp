//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Game.h"

#include "Score.h"
#include "Stopwatch.h"
#include <thread>

#include "BoundingBox.h"
#include "World.h"
#include "Command.h"

turboHiker::Game::Game(std::chrono::duration<double> timeStep, std::unique_ptr<World> world)
    : m_timePerFrame(timeStep), mWorld(std::move(world))
{
}

/**
 * Uses fixed timestep on to maintain a steady framerate for logic updates. The framerate may be more / less laggy
 * depending on your system
 */
void turboHiker::Game::startRunning()
{

        turboHiker::Stopwatch clock2;
        turboHiker::Stopwatch clock;
        std::chrono::duration<double> timeSinceLastUpdate = std::chrono::nanoseconds(0);

        // TODO Set max framerate (optionally) as well (For example: max 60FPS)
        while (isRunning()) {
                processInput();
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > getTimeStep()) {
                        timeSinceLastUpdate -= getTimeStep();

                        processInput();
                        update();
                }

                render();
        }
}

void turboHiker::Game::update() { mWorld->update(getTimeStep()); }
const std::chrono::duration<double>& turboHiker::Game::getTimeStep() const { return m_timePerFrame; }
