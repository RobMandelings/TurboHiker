//
// Created by RobMa on 1/01/2021.
//

#include "Random.h"
#include <mutex>
#include <random>

Random& Random::get()
{

        std::lock_guard<std::mutex> lock(mMutex);

        static Random instance;

        return instance;
}

double Random::randomNumber() { return mDist(mMt); }

Random::Random() { mMt = std::mt19937(mRd()), mDist = std::uniform_real_distribution<double>(0, 1); }

std::mutex Random::mMutex;