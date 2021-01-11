//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "EventObserver.h"
#include <chrono>

namespace turboHiker {
class LiveScore : public EventObserver
{

public:
        LiveScore(int mCollisionPenalty, int mOffendPenalty, int mBasePointRate,
                  const std::chrono::duration<double>& mReferenceDuration);
        void onNotify(const Event& event) override;

        ~LiveScore() override = default;

        int getAmountOfCollisions() const;
        int getCollisionPenalty() const;
        int getHikersYelledAt() const;
        int getYellAtHikerPenalty() const;
        int getBasePointRate() const;
        const std::chrono::duration<double>& getReferenceDuration() const;

        std::chrono::duration<double> getHikeDuration() const;
        int getPointsAtFinish() const;

        void reset();

private:

        int calculatePoints() const;

        /**
         * The time at which the player started hiking
         */
        std::chrono::time_point<std::chrono::system_clock> mStartHike;

        std::chrono::time_point<std::chrono::system_clock> mFinishHike;
        int mPointsAtFinish;

        bool mPlayerFinished;

        int mAmountOfCollisions;
        int mCollisionPenalty;

        int mHikersYelledAt;
        int mYellAtHikerPenalty;

        /**
         * How many points you will earn if you finish the race in exactly the reference duration. If you finish the
         * race in less time, you earn bonus points, otherwise, you lose points
         */
        int mBasePointRate;

        /**
         * This is directly linked to the base point rate. The ratio mReferenceDuration/actualDuration shows by what
         * factor you were late / early. The earlier you finish, the higher this value will be and the more points
         * you'll earn. However, being late means this factor goes < 1, meaning you'll get less and less points the
         * later and later you are.
         */
        std::chrono::duration<double> mReferenceDuration;


};
} // namespace turboHiker
