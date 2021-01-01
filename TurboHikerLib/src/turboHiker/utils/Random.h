//
// Created by RobMa on 1/01/2021.
//

#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <mutex>
#include <random>

class Random
{

public:

        Random(const Random& other) = delete;
        void operator=(const Random& other) = delete;

        static Random& get();

        /**
         * Generates a random number in the range [0, 1]
         * @return the generated random number
         */
        double randomNumber();

private:

        static std::mutex mMutex;

        std::random_device mRd;
        std::mt19937 mMt;
        std::uniform_real_distribution<double> mDist;

        Random();

};

#endif // TURBOHIKER_RANDOM_H
