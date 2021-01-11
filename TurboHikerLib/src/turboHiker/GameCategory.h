//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

namespace turboHiker {
enum GameCategory
{
        GameSceneNode = 1u << 0u,
        GameEntity = 1u << 1u,
        GameStaticHiker = 1u << 2u,
        GameRunningHiker = 1u << 2u,
        GamePlayerHiker = 1u << 3u,
        GameFinish = 1u << 4u,
        GameWorld = 1u << 5u
};
}