//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include <turboHiker/Category.h>

#include "BoundingBox.h"
#include "SceneNodeRenderer.h"
#include "Transformation.h"

turboHiker::Hiker::Hiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
                         std::unique_ptr<SceneNodeRenderer> renderComponent, const Vector2d& initialVelocity)
    : Entity(initialLocation, boundingSize, std::move(renderComponent), initialVelocity, "Hiker")
{
}

unsigned int turboHiker::Hiker::getCategory() const { return Category::Hiker; }
int turboHiker::Hiker::getCurrentLane() const { return mCurrentLane; }
void turboHiker::Hiker::setCurrentLane(int currentLane) { mCurrentLane = currentLane; }
