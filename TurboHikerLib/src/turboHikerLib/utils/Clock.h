//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include <chrono>

namespace turboHikerLib {
class Clock
{

public:
        Clock();

        /**
         * Returns the elapsed time since the previous restart or since creation of the object
         * In nanoseconds: before (using milliseconds) there was a problem where the update would have been called too fast
         * and the millisecond wasn't able to go to one yet but it was already reset, thus breaking the game loop.
         * @return
         */
        std::chrono::nanoseconds restart();

        std::chrono::nanoseconds getElapsedTime() const;

private:
        std::chrono::time_point<std::chrono::system_clock> m_start;
};
} // namespace turboHikerLib