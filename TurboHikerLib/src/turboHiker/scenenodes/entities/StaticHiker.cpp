//
// Created by Rob Mandelings on 11/01/2021.
//

#include "StaticHiker.h"
#include "Random.h"
#include <GameCategory.h>

void turboHiker::StaticHiker::onYelledAt()
{
        bool successful = Random::get().randomNumber() < 0.5;

        if (successful) {
                if (!isMarkedForRemoval()) {
                        markForRemoval();
                }
        }
}

unsigned int turboHiker::StaticHiker::getCategory() const { return GameCategory::GameStaticHiker; }

turboHiker::StaticHiker::StaticHiker(const turboHiker::Vector2d& location, const turboHiker::Vector2d& boundingSize,
                                     const std::string& name)
    : Hiker(location, boundingSize, Vector2d(0, 0), name)
{
}