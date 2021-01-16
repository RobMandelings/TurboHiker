#pragma once

#include <queue>

namespace turboHiker {

class Command;

/**
 * Just a wrapper around a queue which holds commands. The wrapper is useful because if you'd ever need to do something
 * specific first before/after retrieving/pushing the command onto the queue. So the specific implementation of this
 * Command Queue is more hidden than if you would use a plain std::queue.
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