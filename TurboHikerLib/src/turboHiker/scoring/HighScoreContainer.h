//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include <vector>

namespace turboHiker {

class Score;

/**
 * Class which holds the current Best LiveScores of the game
 */
class HighScoreContainer
{

public:
        /**
         * Simple constructor
         * @param maxNr: the maxNr of HighScores kept within this object
         */
        explicit HighScoreContainer(int maxNr);

        /**
         * Adds a new Score to the list of HighScores, if this score beats the lowest highScore that is currently
         * present or if the max capacity of HighScores hasn't been reached yet.
         * @param score: the score of the player
         */
        void addScore(const Score& score);

        /**
         * Returns the list of HighScores currently contained within this HighScore Container
         * @return
         */
        const std::vector<Score>& getHighScores() const;

private:
        /**
         * List of current HighScores
         */
        std::vector<Score> mHighScores;

        /**
         * Max number of HighScores that can be contained within this object
         */
        int mMaxNr;
};
} // namespace turboHiker