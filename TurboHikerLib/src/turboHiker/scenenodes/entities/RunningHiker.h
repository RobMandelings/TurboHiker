//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "Hiker.h"

namespace turboHiker {

/**
 * Hiker that can run on a lane
 */
class RunningHiker : public Hiker
{

public:
        /**
         * Simple constructor
         * @param location: the initial location of the hiker
         * @param boundingSize: the size of the hiker (world coordinates), used for collision detection
         * @param velocity: the initial velocity of the hiker
         * @param name: the name of the hiker
         */
        RunningHiker(const Vector2d& location, const Vector2d& boundingSize, const Vector2d& velocity,
                     const std::string& name);

        /**
         * Simple getter
         * @return the Category of the player hiker
         */
        unsigned int getCategory() const override;

        /**
         * Specific implementation of what happens when the Running hiker is yelled at
         */
        void onYelledAt() override;
};
} // namespace turboHiker