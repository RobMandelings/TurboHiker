//
// Created by Rob Mandelings on 12/12/2020.
//

#include "Clock.h"

turboHikerLib::Clock::Clock() : m_start(std::chrono::high_resolution_clock::now()) {}

std::chrono::milliseconds turboHikerLib::Clock::reset() {
        auto now = std::chrono::high_resolution_clock::now();
        auto difference = now - m_start;
        m_start = now;
        return std::chrono::duration_cast<std::chrono::milliseconds>(difference);
}