//
// Created by RobMa on 4/01/2021.
//

#include "PlayerHiker.h"
#include "GameCategory.h"
#include "Renderer.h"
#include <cassert>

turboHiker::PlayerHiker::PlayerHiker(const Vector2d& location, const Vector2d& size, const std::string& name,
                                     double slowSpeed, double fastSpeed)
    : Hiker(location, size, Vector2d(0,0), name), mSlowSpeed(slowSpeed), mFastSpeed(fastSpeed)
{
        assert(slowSpeed <= fastSpeed && "The slow speed should be slower than the fast speed of the player hiker");
}

unsigned int turboHiker::PlayerHiker::getCategory() const { return GameCategory::GamePlayerHiker; }

bool turboHiker::PlayerHiker::goingFast() const { return getVelocity().y == mFastSpeed; }

double turboHiker::PlayerHiker::getFastSpeed() const { return mFastSpeed; }
double turboHiker::PlayerHiker::getSlowSpeed() const { return mSlowSpeed; }

void turboHiker::PlayerHiker::goFast() { setVelocity(Vector2d(getVelocity().x, mFastSpeed)); }
void turboHiker::PlayerHiker::goSlow() { setVelocity(Vector2d(getVelocity().x, mSlowSpeed)); }

void turboHiker::PlayerHiker::onYelledAt()
{
        // Do nothing
}