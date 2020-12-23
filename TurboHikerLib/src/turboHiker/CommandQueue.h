#pragma once

#include "Command.h"

#include <queue>

namespace turboHiker {
class CommandQueue
{
public:
        void push(const Command& command);
        Command pop();
        bool isEmpty() const;

private:
        std::queue<Command> mQueue;
};
} // namespace turboHiker