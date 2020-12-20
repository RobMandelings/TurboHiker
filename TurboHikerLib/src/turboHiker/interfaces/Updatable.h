//
// Created by RobMa on 20/12/2020.
//

#ifndef TURBOHIKER_UPDATABLE_H
#define TURBOHIKER_UPDATABLE_H

#include <chrono>

class Updatable
{

public:

        typedef std::chrono::duration<double> seconds;

        virtual void update(seconds dt) = 0;
};

#endif // TURBOHIKER_UPDATABLE_H
