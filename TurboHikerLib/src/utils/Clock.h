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

        std::chrono::milliseconds reset();

private:
        std::chrono::time_point<std::chrono::system_clock> m_start;
};
} // namespace turboHikerLib