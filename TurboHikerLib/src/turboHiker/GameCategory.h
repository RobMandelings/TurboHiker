//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

namespace turboHiker {

/**
 * Used to easily check which type of Type it is so it can be casted. Very important that SceneNodes who are not of
 * this type should not use the specific Game category, but this is easy to check. It eliminates the need of dynamic
 * down casting if it would ever be necessary.
 */
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
} // namespace turboHiker