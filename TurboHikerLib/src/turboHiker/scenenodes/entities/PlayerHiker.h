//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_PLAYERHIKER_H
#define TURBOHIKER_PLAYERHIKER_H

#include "Hiker.h"

namespace turboHiker {

/**
 * Hiker that represents the player. May either move faster, or slower
 */
class PlayerHiker : protected Hiker
{

public:

        /**
         * Simple constructor
         * @param location: the initial location of the hiker
         * @param size: the size of the hiker (world coordinates), used for collision detection
         * @param velocity: the initial velocity of the hiker
         * @param name: the name of the hiker
         * @param slowSpeed: the speed value at which the hiker moves slower
         * @param fastSpeed: the speed value at which the hiker moves faster
         */
        PlayerHiker(const Vector2d& location, const Vector2d& size, const std::string& name, double slowSpeed,
                    double fastSpeed);

        /**
         * Checks whether or not the hiker is going fast (at speed: fastSpeed) or not
         * @return true if the hiker is moving fast
         */
        bool goingFast() const;

        /**
         * The speed at which the hiker moves fast
         * @return true if the hiker moves fast
         */
        double getFastSpeed() const;

        /**
         * The speed at which the hiker moves slow
         * @return true if the hiker moves slow
         */
        double getSlowSpeed() const;

        /**
         * Makes the player hiker go fast
         */
        void goFast();

        /**
         * Makes the player hiker go slow
         */
        void goSlow();

        /**
         * Simple getter
         * @return the Category of the player hiker
         */
        unsigned int getCategory() const override;

        /**
         * Implementation of what happens when the hiker is yelled at
         */
        void onYelledAt() override;

private:

        /**
         * The speed at which the hiker moves fast
         */
        double mFastSpeed;

        /**
         * The speed at which the hiker moves slow
         */
        double mSlowSpeed;
};
} // namespace turboHiker

#endif // TURBOHIKER_PLAYERHIKER_H