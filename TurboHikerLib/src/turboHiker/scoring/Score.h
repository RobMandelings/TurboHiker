//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "EventObserver.h"
#include <chrono>

namespace turboHiker {

/**
 * Keeps track of the score of a hike. Each time a hike is started, the previous
 * score will be added to the HighScore container (if its a new HighScore) and the score will be reset
 */
class Score : public EventObserver
{

public:
        /**
         * Simple constructor
         * @param mCollisionPenalty: the penalty (minus points) when a hiker collides with another hiker
         * @param mOffendPenalty: the penalty (minus points) if a hiker gets offended (i.e a Successful yell)
         * @param mBasePointRate: the base point rate that is reached when the player finished a hike at exactly the
         * reference duration. If the player takes longer to do so, less points will be given. If the player takes a
         * shorter time however, more points shall be given
         * @param mReferenceDuration: the reference duration, used together with the base point rate
         */
        Score(int mCollisionPenalty, int mOffendPenalty, int mBasePointRate,
              const std::chrono::duration<double>& mReferenceDuration);
        void onNotify(const Event& event) override;

        /**
         * Simple destructor
         */
        ~Score() override = default;

        /**
         * Simple getter
         * @return the amount of hikers that the player has collided with
         */
        int getAmountOfCollisions() const;

        /**
         * Simple getter
         * @return the penalty (minus points) given to a player who collides with another hiker
         */
        int getCollisionPenalty() const;

        /**
         * Simple getter
         * @return the nummber of hikers that the player yelled at
         */
        int getHikersYelledAt() const;

        /**
         * Simple getter
         * @return the penalty (minus points) given to a player who manages to successfully yell at another hiker
         */
        int getYellAtHikerPenalty() const;

        /**
         * Simple getter
         * @return the base point rate of a hike
         */
        int getBasePointRate() const;

        /**
         * Simple getter
         * @return the reference duration of a hike
         */
        const std::chrono::duration<double>& getReferenceDuration() const;

        /**
         * @return The current duration of hiking. Used to calculate the final points total
         */
        std::chrono::duration<double> getHikeDuration() const;

        /**
         * Simple getter
         * @return the points at finish
         */
        int getPointsAtFinish() const;

        /**
         * Resets the liveScore so it is as the game hasn't started yet
         */
        void reset();

private:

        /**
         * Calculates the current amount of points you've managed to acquire at the end of the hike
         * @return the amount of points
         */
        int calculatePoints() const;

        /**
         * The time at which the player started hiking
         */
        std::chrono::time_point<std::chrono::system_clock> mStartHike;

        /**
         * The time at which the player ended hiking
         */
        std::chrono::time_point<std::chrono::system_clock> mFinishHike;

        /**
         * The points the player managed to acquire at the end of the hike
         */
        int mPointsAtFinish;

        /**
         * True if the player finished its hike, false if not
         */
        bool mPlayerFinished;

        /**
         * The amount of collisions the hiker has
         */
        int mAmountOfCollisions;

        /**
         * The penalty for colliding with another hiker
         */
        int mCollisionPenalty;

        /**
         * The amount of hikers that you've yelled at
         */
        int mHikersYelledAt;

        /**
         * The penalty for offending a hiker (successful yell)
         */
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
