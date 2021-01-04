//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_COMMANDABLE_H
#define TURBOHIKER_COMMANDABLE_H

#endif // TURBOHIKER_COMMANDABLE_H

namespace turboHiker {

class Command;

class Commandable
{

public:
        virtual void onCommand(const Command& command, Updatable::seconds dt) = 0;
};
}