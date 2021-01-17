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

        /**
         * Pushes a command onto the command queue
         * @param command: the command to push
         */
        void push(const Command& command);

        /**
         * Pops a command from the command queue
         * @return the popped command
         */
        Command pop();

        /**
         * Checks if the command queue is empty
         * @return true if this is the case, false if not
         */
        bool isEmpty() const;

private:

        /**
         * The queue internally, used by the CommandQueue
         */
        std::queue<Command> mQueue;
};
} // namespace turboHiker