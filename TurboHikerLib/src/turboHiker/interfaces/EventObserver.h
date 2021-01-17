//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

namespace turboHiker {

/**
 * Enum to denote events received by the EventObserver
 */
enum class Event
{
        PLAYER_COLLIDED,
        YELLED_AT_HIKER,
        PLAYER_STARTED,
        PLAYER_FINISHED,
        PLAYER_SLOWED_DOWN,
        PLAYER_SPED_UP
};

/**
 * Observer which receives events
 */
class EventObserver
{

public:

        /**
         * Destructor for the event observer
         */
        virtual ~EventObserver() = default;

        /**
         * Called whenever the observer is notified of an event that happened
         * @param event: the event that happened
         */
        virtual void onNotify(const Event& event) = 0;
};

} // namespace turboHiker