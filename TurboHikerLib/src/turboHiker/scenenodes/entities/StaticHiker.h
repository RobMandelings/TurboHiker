//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "Hiker.h"

namespace turboHiker {

/** Hiker that doesn't move on a lane */
class StaticHiker : public Hiker
{

public:
        /**
         * Simple constructor
         * @param location: the initial location of the hiker
         * @param boundingSize: the size of the hiker (world coordinates), used for collision detection
         * @param velocity: the initial velocity of the hiker
         * @param name: the name of the hiker
         */
        StaticHiker(const turboHiker::Vector2d& location, const turboHiker::Vector2d& boundingSize,
                    const std::string& name);

public:
        /**
         * Specific implementation of what happens when the hiker is yelled at
         */
        void onYelledAt() override;

        /**
         * @return the category of the hiker
         */
        unsigned int getCategory() const override;
};
} // namespace turboHiker