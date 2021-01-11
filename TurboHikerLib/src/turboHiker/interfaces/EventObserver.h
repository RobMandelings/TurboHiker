//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

namespace turboHiker {

enum class Event
{
        PLAYER_COLLIDED,
        YELLED_AT_HIKER,
        PLAYER_STARTED,
        PLAYER_FINISHED,
        PLAYER_SLOWED_DOWN,
        PLAYER_SPED_UP
};

class EventObserver
{

public:
        virtual ~EventObserver() = default;
        virtual void onNotify(const Event& event) = 0;
};

} // namespace turboHiker