//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_WORLDSTATS_H
#define TURBOHIKER_WORLDSTATS_H

#include "enums.h"

namespace turboHiker {

struct WorldStats
{

        WorldStats(HikeStatus hikeStatus, int currentPoints, bool playerFast);

        HikeStatus hikeStatus;
        int points;
        bool playerFast;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLDSTATS_H
