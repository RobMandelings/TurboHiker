//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"

namespace turboHiker {

/**
 * Entity which can be put on lanes and can be yelled at. Specific implementation of what happens when a hiker is yelled
 * at is done in the child classes
 */
class Hiker : public Entity
{

public:
        /**
         * Simple constructor
         * @param location: the initial location of the hiker
         * @param size: the size of the hiker (world coordinates), used for collision detection
         * @param velocity: the initial velocity of the hiker
         * @param name: the name of the hiker
         */
        Hiker(const Vector2d& location, const Vector2d& size, const Vector2d& velocity,
              const std::string& name);

        void update(seconds dt) override;

        void setDestinationX(double destinationX);

        /**
         * Simple getter
         * @return which lane the hiker is currently at
         */
        int getCurrentLane() const;

        /**
         * Simple setter
         * @param lane: the lane to put the hiker at
         */
        void setCurrentLane(int lane);

        /**
         * Something that happens when a hiker is yelled at
         */
        virtual void onYelledAt() = 0;

private:

        bool destinationXReached() const;

        double mAccelerationX;
        double mMaxVelocityX;

        bool mHasDestinationX;
        double mDestinationX;

        /**
         * The current lane of the hiker
         */
        int mCurrentLane;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKER_H
