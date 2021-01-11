//
// Created by RobMa on 4/01/2021.
//

#include "WorldStats.h"
#include "HikeStatus.h"

turboHiker::WorldStats::WorldStats(HikeStatus hikeStatus, int currentPoints, bool playerFast)
    : hikeStatus(hikeStatus), points(currentPoints), playerFast(playerFast)
{
}