#pragma once

// Entity/scene node category, used to dispatch commands
namespace turboHiker::Category {
enum Type
{
        None = 0,
        Scene = 1 << 0,
        PlayerHiker = 1 << 1,
        Hiker = 1 << 2,
};
} // namespace turboHiker