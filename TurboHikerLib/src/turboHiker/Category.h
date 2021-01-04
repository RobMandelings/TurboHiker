#pragma once

// SceneNode/scene node category, used to dispatch commands
namespace turboHiker {
enum GameCategory
{
        GameSceneNode = 1u << 0u,
        GameEntity = 1u << 1u,
        GameHiker = 1u << 2u,
        GamePlayerHiker = 1u << 3u,
        GameWorld = 1u << 4u
};

enum class HikeStatus
{
        BeforeHiking,
        WhilstHiking,
        AfterHiking
};
} // namespace turboHiker