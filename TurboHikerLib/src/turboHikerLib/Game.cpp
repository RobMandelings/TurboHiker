//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Game.h"

#include "Clock.h"
#include <cassert>
#include <iostream>
#include <thread>

turboHiker::Game::Game(std::chrono::nanoseconds timePerFrame) : m_timePerFrame(timePerFrame), m_isRunning(false) {}

/**
 * Uses fixed timestep on to maintain a steady framerate for logic updates. The framerate may be more / less laggy
 * depending on your system
 */
void turboHiker::Game::startRunning()
{
        // TODO how to debug?
        assert(!isRunning() && "The game is already running!");
        m_isRunning = true;

        turboHiker::Clock clock2;
        turboHiker::Clock clock;
        std::chrono::nanoseconds timeSinceLastUpdate = std::chrono::milliseconds(0);

        std::cout << "The updateTimeStep is: " << m_timePerFrame.count() << std::endl;
        // Set max framerate (optionally) as well (For example: max 60FPS)
        while (isRunning()) {
                processInputEvents();
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > getTimePerFrame()) {
                        std::cout << "Smallert loop" << std::endl;

                        timeSinceLastUpdate -= getTimePerFrame();
                        processInputEvents();
                        update();
                }
                render();
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Time passed in milliseconds: " << clock2.restart().count();
}

void turboHiker::Game::stopRunning() { m_isRunning = false; }

bool turboHiker::Game::isRunning() const { return m_isRunning; }

void turboHiker::Game::update()
{
        // world.update();
}
const std::chrono::nanoseconds& turboHiker::Game::getTimePerFrame() const { return m_timePerFrame; }
