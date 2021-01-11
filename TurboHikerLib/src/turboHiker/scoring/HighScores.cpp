//
// Created by Rob Mandelings on 11/01/2021.
//

#include "HighScores.h"
#include "LiveScore.h"
#include <algorithm>
#include <cassert>

turboHiker::HighScores::HighScores(int maxNr) : mMaxNr(maxNr) {}

void turboHiker::HighScores::addScore(const turboHiker::LiveScore& liveScore)
{

        if (mHighScores.size() == mMaxNr) {
                auto lowestScoreIt = mHighScores.begin();
                for (auto highScoreIt = mHighScores.begin(); highScoreIt < mHighScores.end(); highScoreIt++) {
                        if (highScoreIt->getPointsAtFinish() < lowestScoreIt->getPointsAtFinish()) {
                                lowestScoreIt = highScoreIt;
                        }
                }

                if (liveScore.getPointsAtFinish() > lowestScoreIt->getPointsAtFinish()) {
                        mHighScores.erase(lowestScoreIt);
                        mHighScores.push_back(liveScore);
                }
        } else {
                mHighScores.push_back(liveScore);
        }

        std::sort(mHighScores.begin(), mHighScores.end(), [](const LiveScore& lhs, const LiveScore& rhs) {
                return lhs.getPointsAtFinish() > rhs.getPointsAtFinish();
        });

        assert(mHighScores.size() <= 5);
}

const std::vector<turboHiker::LiveScore>& turboHiker::HighScores::getHighScores() const { return mHighScores; }