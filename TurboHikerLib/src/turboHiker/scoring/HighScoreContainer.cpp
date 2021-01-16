//
// Created by Rob Mandelings on 11/01/2021.
//

#include "HighScoreContainer.h"
#include "Score.h"
#include <algorithm>
#include <cassert>

turboHiker::HighScoreContainer::HighScoreContainer(int maxNr) : mMaxNr(maxNr) {}

void turboHiker::HighScoreContainer::addScore(const turboHiker::Score& score)
{

        if (mHighScores.size() == mMaxNr) {
                auto lowestScoreIt = mHighScores.begin();
                for (auto highScoreIt = mHighScores.begin(); highScoreIt < mHighScores.end(); highScoreIt++) {
                        if (highScoreIt->getPointsAtFinish() < lowestScoreIt->getPointsAtFinish()) {
                                lowestScoreIt = highScoreIt;
                        }
                }

                if (score.getPointsAtFinish() > lowestScoreIt->getPointsAtFinish()) {
                        mHighScores.erase(lowestScoreIt);
                        mHighScores.push_back(score);
                }
        } else {
                mHighScores.push_back(score);
        }

        std::sort(mHighScores.begin(), mHighScores.end(), [](const Score& lhs, const Score& rhs) {
                return lhs.getPointsAtFinish() > rhs.getPointsAtFinish();
        });

        assert(mHighScores.size() <= 5);
}

const std::vector<turboHiker::Score>& turboHiker::HighScoreContainer::getHighScores() const { return mHighScores; }