//
// Created by Rob Mandelings on 11/01/2021.
//

#include "RunningHiker.h"
#include <GameCategory.h>
#include <Random.h>

turboHiker::RunningHiker::RunningHiker(const turboHiker::Vector2d& location, const turboHiker::Vector2d& boundingSize,
                                       const turboHiker::Vector2d& velocity, const std::string& name)
    : Hiker(location, boundingSize, velocity, name)
{
}

unsigned int turboHiker::RunningHiker::getCategory() const { return GameCategory::GameRunningHiker; }

void turboHiker::RunningHiker::onYelledAt()
{
        bool successful = Random::get().randomNumber() < 0.5;

        if (successful) {
                mVelocity.y /= 4;
        }
}