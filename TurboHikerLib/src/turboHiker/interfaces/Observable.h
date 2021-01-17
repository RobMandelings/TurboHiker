//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include <memory>
#include <vector>

namespace turboHiker {

class EventObserver;
enum class Event;

/**
 * Implement this if you want other objects to register to this class in order to receive events
 */
class Observable
{

public:

        /**
         * Notifies all observers listening that a certain event happened
         * @param event: the event that happened
         */
        void notify(Event event);

        /**
         * Register a new observer to this class so it can start receiving notifications of events
         * @param observer: the observer to add
         */
        void addObserver(const std::shared_ptr<EventObserver>& observer);

        /**
         * Remove an observer from the list of observers
         * @param observer: observer to remove
         */
        void removeObserver(const std::shared_ptr<EventObserver>& observer);

private:

        /**
         * List of observers
         */
        std::vector<std::shared_ptr<EventObserver>> mObservers;
};
} // namespace turboHiker