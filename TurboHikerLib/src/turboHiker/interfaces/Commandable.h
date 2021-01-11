//
// Created by RobMa on 4/01/2021.
//

#pragma once

#include "Updatable.h"

namespace turboHiker {

class Command;

class Commandable
{

public:
        virtual void onCommand(const Command& command, Updatable::seconds dt) = 0;
};
} // namespace turboHiker