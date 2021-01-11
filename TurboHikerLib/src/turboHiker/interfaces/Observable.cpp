//
// Created by Rob Mandelings on 11/01/2021.
//

#include "Observable.h"

#include <algorithm>
#include <cassert>

#include "EventObserver.h"

void turboHiker::Observable::notify(turboHiker::Event event)
{
        for (const std::shared_ptr<EventObserver>& eventObserver : mObservers) {
                eventObserver->onNotify(event);
        }
}
void turboHiker::Observable::addObserver(const std::shared_ptr<EventObserver>& observer)
{
        auto found = std::find_if(
            mObservers.begin(), mObservers.end(),
            [&observer](const std::shared_ptr<EventObserver>& otherObserver) { return observer == otherObserver; });
        assert(found == mObservers.end());
        mObservers.push_back(observer);
}
void turboHiker::Observable::removeObserver(const std::shared_ptr<EventObserver>& observer)
{
        auto found = std::find_if(mObservers.begin(), mObservers.end(), [&observer](const std::shared_ptr<EventObserver>& otherObserver) { return observer == otherObserver; });
        assert(found != mObservers.end());
        mObservers.erase(found);
}
