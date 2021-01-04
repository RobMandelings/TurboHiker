#pragma once

// SceneNode/scene node category, used to dispatch commands
namespace turboHiker {
enum GameCategory
{
        Scene = 1u << 0u,
        CompetingHiker = 1u << 1u,
        PlayerHiker = 1u << 2u,
        GameWorld = 1u << 3u
};
}