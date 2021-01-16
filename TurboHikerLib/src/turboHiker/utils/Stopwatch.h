//
// Created by Rob Mandelings on 12/12/2020.
//

#pragma once

#include <chrono>

namespace turboHiker {

/**
 * Conveniently track the duration between the creation / restart of the clock and the time the elapsed time is queried.
 */
class Stopwatch
{

public:
        /**
         * Simple constructor
         */
        Stopwatch();

        /**
         * Returns the elapsed time since the previous restart or since creation of the object
         * In nanoseconds: before (using milliseconds) there was a problem where the update would have been called too
         * fast and the millisecond wasn't able to go to one yet but it was already reset, thus breaking the game loop.
         * @return
         */
        std::chrono::nanoseconds restart();

        /**
         * Returns the current time elapsed between creation / restart and now.
         */
        std::chrono::nanoseconds getElapsedTime() const;

private:
        /**
         * The time at which the Stopwatch was created / restarted.
         */
        std::chrono::time_point<std::chrono::system_clock> m_start;
};
} // namespace turboHiker