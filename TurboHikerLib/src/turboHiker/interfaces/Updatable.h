//
// Created by RobMa on 20/12/2020.
//

#ifndef TURBOHIKER_UPDATABLE_H
#define TURBOHIKER_UPDATABLE_H

#include <chrono>

namespace turboHiker {

/**
 * Abstract class which contains an update function
 */
class Updatable
{

public:

        /**
         * The chrono duration, used as deltaTime, in seconds (double value)
         */
        typedef std::chrono::duration<double> seconds;

        /**
         * Update the object by the given timestep
         * @param dt: the timestep
         */
        virtual void update(seconds dt) = 0;
};
} // namespace turboHiker

#endif // TURBOHIKER_UPDATABLE_H
