//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

namespace turboHiker {

/**
 * Represents the HikeStatus the world is currently in
 */
enum HikeStatus
{
        BeforeHiking = 1u << 1,
        WhilstHiking = 1u << 2,
        AfterHiking = 1u << 3
};
}