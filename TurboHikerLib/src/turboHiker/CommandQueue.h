#pragma once

#include "Command.h"

#include <queue>

namespace turboHiker {

/**
 * Just a wrapper around a queue which holds commands. The wrapper is useful because if you'd ever need to do something
 * specific first before/after retrieving/pushing the command onto the queue
 */
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