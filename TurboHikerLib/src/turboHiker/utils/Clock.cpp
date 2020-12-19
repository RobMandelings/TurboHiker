//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Clock.h"

turboHiker::Clock::Clock() : m_start(std::chrono::high_resolution_clock::now()) {}

std::chrono::nanoseconds turboHiker::Clock::restart()
{
        auto now = std::chrono::high_resolution_clock::now();
        auto difference = now - m_start;
        m_start = now;
        return difference;
}

std::chrono::nanoseconds turboHiker::Clock::getElapsedTime() const
{
        return std::chrono::high_resolution_clock::now() - m_start;
}