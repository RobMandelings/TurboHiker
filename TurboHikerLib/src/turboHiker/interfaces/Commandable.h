//
// Created by RobMa on 4/01/2021.
//

#pragma once

#include "Updatable.h"

namespace turboHiker {

class Command;

/**
 * If you want to execute commands, you need to implement this function
 */
class Commandable
{

public:

        /**
         * Does something with the command given, probably execute it
         * @param command: the command
         * @param dt: the TimeStep for time-based commands
         */
        virtual void onCommand(const Command& command, Updatable::seconds dt) = 0;
};
} // namespace turboHiker