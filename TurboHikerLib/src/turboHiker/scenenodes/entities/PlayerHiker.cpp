//
// Created by RobMa on 4/01/2021.
//

#include "PlayerHiker.h"
#include "Category.h"
#include "SceneNodeRenderer.h"
#include <cassert>

turboHiker::PlayerHiker::PlayerHiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
                                     std::unique_ptr<SceneNodeRenderer> renderComponent,
                                     const Vector2d& initialVelocity, const std::string& name, double slowSpeed,
                                     double fastSpeed)
    : Hiker(initialLocation, boundingSize, std::move(renderComponent), initialVelocity, name), mSlowSpeed(slowSpeed),
      mFastSpeed(fastSpeed)
{
}

unsigned int turboHiker::PlayerHiker::getCategory() const { return GameCategory::GamePlayerHiker; }

bool turboHiker::PlayerHiker::goingFast() const {

        return getVelocity().y == mFastSpeed;
}

double turboHiker::PlayerHiker::getFastSpeed() const { return mFastSpeed; }
double turboHiker::PlayerHiker::getSlowSpeed() const { return mSlowSpeed; }

void turboHiker::PlayerHiker::goFast() { setVelocity(Vector2d(getVelocity().x, mFastSpeed)); }
void turboHiker::PlayerHiker::goSlow() { setVelocity(Vector2d(getVelocity().x, mSlowSpeed)); }