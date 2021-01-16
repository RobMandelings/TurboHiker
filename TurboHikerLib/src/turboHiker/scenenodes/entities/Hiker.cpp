//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include "Renderer.h"
#include "Transformation.h"
#include <cmath>

turboHiker::Hiker::Hiker(const Vector2d& location, const Vector2d& size, const Vector2d& velocity,
                         const std::string& name)
    : Entity(location, size, velocity, name), mHasDestinationX(false), mDestinationX(0), mMaxVelocityX(500),
      mAccelerationX(10), mCurrentLane(0)
{
}

void turboHiker::Hiker::setDestinationX(double destinationX)
{
        mDestinationX = destinationX;
        mVelocity.x = mMaxVelocityX * (destinationX - mLocation.x > 0 ? 1 : -1);
        mHasDestinationX = true;
}
bool turboHiker::Hiker::destinationXReached() const
{
        return mVelocity.x > 0 && mDestinationX - mLocation.x <= 0 ||
               mVelocity.x < 0 && mDestinationX - mLocation.x >= 0;
}

int turboHiker::Hiker::getCurrentLane() const { return mCurrentLane; }

void turboHiker::Hiker::setCurrentLane(int lane) { mCurrentLane = lane; }
void turboHiker::Hiker::update(turboHiker::Updatable::seconds dt)
{
        Entity::update(dt);

        if (destinationXReached()) {
                mVelocity.x = 0;
                mLocation.x = mDestinationX;
                mHasDestinationX = false;
        }
}
