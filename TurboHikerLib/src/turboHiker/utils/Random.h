//
// Created by RobMa on 1/01/2021.
//

#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <mutex>
#include <random>

/**
 * Singleton class that easily generates a number in range [0, 1].
 */
class Random
{

public:

        /** Deleted copy constructor as its a singleton class */
        Random(const Random& other) = delete;

        /** Deleted assignment operator as its a singleton class */
        void operator=(const Random& other) = delete;

        /**
         * Simple getter
         * @return the instance of the Random class
         */
        static Random& get();

        /**
         * Generates a random number in the range [0, 1]
         * @return the generated random number
         */
        double randomNumber();

private:

        /**
         * Variable to ensure mutual exclusion in case of working in a multithreade environnement
         */
        static std::mutex mMutex;

        /**
         * Basic members for generating random numbers
         */
        std::random_device mRd;
        std::mt19937 mMt;
        std::uniform_real_distribution<double> mDist;

        /**
         * Make the constructor private as its a singleton class
         */
        Random();

};

#endif // TURBOHIKER_RANDOM_H
