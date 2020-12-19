//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Game.h"

#include "Clock.h"
#include <cassert>
#include <iostream>
#include <thread>

turboHiker::Game::Game(std::chrono::duration<double> timePerFrame) : m_timePerFrame(timePerFrame), m_isRunning(false) {}

/**
 * Uses fixed timestep on to maintain a steady framerate for logic updates. The framerate may be more / less laggy
 * depending on your system
 */
void turboHiker::Game::startRunning()
{
        assert(!isRunning() && "The game is already running!");
        m_isRunning = true;

        turboHiker::Clock clock2;
        turboHiker::Clock clock;
        std::chrono::duration<double> timeSinceLastUpdate = std::chrono::nanoseconds(0);

        // TODO call update function with std::chrono::duration<float> (in seconds)
        std::cout << "The updateTimeStep is: " << m_timePerFrame.count() << std::endl;
        // TODO Set max framerate (optionally) as well (For example: max 60FPS)
        while (isRunning()) {
                processInputEvents();
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > getTimeStep()) {
                        std::cout << "Smaller loop" << std::endl;

                        timeSinceLastUpdate -= getTimeStep();
                        processInputEvents();
                        update();
                }
                render();
        }
}

void turboHiker::Game::stopRunning() { m_isRunning = false; }

bool turboHiker::Game::isRunning() const { return m_isRunning; }

void turboHiker::Game::update()
{
        // world.update();
}
const std::chrono::duration<double>& turboHiker::Game::getTimeStep() const { return m_timePerFrame; }
