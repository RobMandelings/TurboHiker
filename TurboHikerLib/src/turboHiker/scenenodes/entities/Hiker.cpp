//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include "Renderer.h"
#include "Transformation.h"

turboHiker::Hiker::Hiker(const Vector2d& location, const Vector2d& boundingSize, const Vector2d& velocity,
                         const std::string& name)
    : Entity(location, boundingSize, velocity, name)
{
}

int turboHiker::Hiker::getCurrentLane() const { return mCurrentLane; }

void turboHiker::Hiker::setCurrentLane(int currentLane) { mCurrentLane = currentLane; }