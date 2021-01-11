//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include <memory>
#include <vector>

namespace turboHiker {

class EventObserver;
enum class Event;

class Observable
{

public:

        void notify(Event event);

        void addObserver(const std::shared_ptr<EventObserver>& observer);

        void removeObserver(const std::shared_ptr<EventObserver>& observer);

private:
        std::vector<std::shared_ptr<EventObserver>> mObservers;
};
} // namespace turboHiker