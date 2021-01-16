//
// Created by Rob Mandelings on 11/01/2021.
//

#include "Score.h"

turboHiker::Score::Score(int mCollisionPenalty, int mOffendPenalty, int mBasePointRate,
                                 const std::chrono::duration<double>& mReferenceDuration)
    : mCollisionPenalty(mCollisionPenalty), mYellAtHikerPenalty(mOffendPenalty), mBasePointRate(mBasePointRate),
      mReferenceDuration(mReferenceDuration), mHikersYelledAt(0), mAmountOfCollisions(0), mPointsAtFinish(0), mPlayerFinished(false)
{
}

void turboHiker::Score::onNotify(const turboHiker::Event& event)
{

        if (event == Event::PLAYER_STARTED) {
                mStartHike = std::chrono::high_resolution_clock::now();
        } else if (event == Event::PLAYER_FINISHED) {
                mFinishHike = std::chrono::high_resolution_clock::now();
                mPlayerFinished = true;
                mPointsAtFinish = calculatePoints();
        } else if (event == Event::PLAYER_COLLIDED) {
                mAmountOfCollisions++;
        } else if (event == Event::YELLED_AT_HIKER) {
                mHikersYelledAt++;
        }
}

int turboHiker::Score::calculatePoints() const
{

        std::chrono::duration<double> actualDuration = (mFinishHike - mStartHike);

        double pointsOnFinish = mBasePointRate * (mReferenceDuration / actualDuration);

        pointsOnFinish -= mAmountOfCollisions * mCollisionPenalty;
        pointsOnFinish -= mHikersYelledAt * mYellAtHikerPenalty;

        return static_cast<int>(pointsOnFinish);
}

int turboHiker::Score::getAmountOfCollisions() const { return mAmountOfCollisions; }
int turboHiker::Score::getCollisionPenalty() const { return mCollisionPenalty; }
int turboHiker::Score::getHikersYelledAt() const { return mHikersYelledAt; }
int turboHiker::Score::getYellAtHikerPenalty() const { return mYellAtHikerPenalty; }
int turboHiker::Score::getBasePointRate() const { return mBasePointRate; }
const std::chrono::duration<double>& turboHiker::Score::getReferenceDuration() const { return mReferenceDuration; }
int turboHiker::Score::getPointsAtFinish() const { return mPointsAtFinish; }

std::chrono::duration<double> turboHiker::Score::getHikeDuration() const
{

        // If the player has finished its hike, the time at which the player finished is constant. Otherwise, the
        // duration keeps on getting bigger until the player reached the finish
        return (mPlayerFinished ? mFinishHike : std::chrono::high_resolution_clock::now()) - mStartHike;
}

void turboHiker::Score::reset() {
        mPlayerFinished = false;
        mPointsAtFinish = 0;
        mAmountOfCollisions = 0;
        mHikersYelledAt = 0;
}
