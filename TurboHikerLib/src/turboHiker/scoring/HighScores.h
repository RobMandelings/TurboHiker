//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include <vector>

namespace turboHiker {

class LiveScore;

class HighScores
{

public:
        explicit HighScores(int maxNr);

        void addScore(const LiveScore& liveScore);

        const std::vector<LiveScore>& getHighScores() const;

private:

        std::vector<LiveScore> mHighScores;

        int mMaxNr;
};
} // namespace turboHiker