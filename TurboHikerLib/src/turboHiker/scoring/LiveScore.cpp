//
// Created by Rob Mandelings on 11/01/2021.
//

#include "LiveScore.h"

turboHiker::LiveScore::LiveScore(int mCollisionPenalty, int mOffendPenalty, int mBasePointRate,
                                 const std::chrono::duration<double>& mReferenceDuration)
    : mCollisionPenalty(mCollisionPenalty), mYellAtHikerPenalty(mOffendPenalty), mBasePointRate(mBasePointRate),
      mReferenceDuration(mReferenceDuration), mHikersYelledAt(0), mAmountOfCollisions(0), mPointsAtFinish(0), mPlayerFinished(false)
{
}

void turboHiker::LiveScore::onNotify(const turboHiker::Event& event)
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

int turboHiker::LiveScore::calculatePoints() const
{

        std::chrono::duration<double> actualDuration = (mFinishHike - mStartHike);

        double pointsOnFinish = mBasePointRate * (mReferenceDuration / actualDuration);

        pointsOnFinish -= mAmountOfCollisions * mCollisionPenalty;
        pointsOnFinish -= mHikersYelledAt * mYellAtHikerPenalty;

        return static_cast<int>(pointsOnFinish);
}

int turboHiker::LiveScore::getAmountOfCollisions() const { return mAmountOfCollisions; }
int turboHiker::LiveScore::getCollisionPenalty() const { return mCollisionPenalty; }
int turboHiker::LiveScore::getHikersYelledAt() const { return mHikersYelledAt; }
int turboHiker::LiveScore::getYellAtHikerPenalty() const { return mYellAtHikerPenalty; }
int turboHiker::LiveScore::getBasePointRate() const { return mBasePointRate; }
const std::chrono::duration<double>& turboHiker::LiveScore::getReferenceDuration() const { return mReferenceDuration; }
int turboHiker::LiveScore::getPointsAtFinish() const { return mPointsAtFinish; }

std::chrono::duration<double> turboHiker::LiveScore::getHikeDuration() const
{

        // If the player has finished its hike, the time at which the player finished is constant. Otherwise, the
        // duration keeps on getting bigger until the player reached the finish
        return (mPlayerFinished ? mFinishHike : std::chrono::high_resolution_clock::now()) - mStartHike;
}

void turboHiker::LiveScore::reset() {
        mPlayerFinished = false;
        mPointsAtFinish = 0;
        mAmountOfCollisions = 0;
        mHikersYelledAt = 0;
}
