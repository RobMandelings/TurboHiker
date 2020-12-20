//
// Created by RobMa on 19/12/2020.
//

#include "GameObject.h"

namespace turboHiker {
void GameObject::draw() const {}
void GameObject::update(Updatable::seconds dt) {}

const Vector2d& GameObject::getCurrentLocation() const { return mCurrentLocation; }
void GameObject::setCurrentLocation(const Vector2d& currentLocation)
{
        mCurrentLocation = currentLocation;
}
} // namespace turboHiker