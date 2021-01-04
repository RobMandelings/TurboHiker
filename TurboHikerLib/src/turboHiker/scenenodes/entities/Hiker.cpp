//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include <turboHiker/enums.h>

#include "Random.h"
#include "SceneNodeRenderer.h"
#include "Transformation.h"

turboHiker::Hiker::Hiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
                         std::unique_ptr<SceneNodeRenderer> renderComponent, const Vector2d& initialVelocity,
                         const std::string& name)
    : Entity(initialLocation, boundingSize, std::move(renderComponent), initialVelocity, name)
{
}

unsigned int turboHiker::Hiker::getCategory() const
{
        return GameCategory::GameHiker;
}
int turboHiker::Hiker::getCurrentLane() const { return mCurrentLane; }
void turboHiker::Hiker::setCurrentLane(int currentLane) { mCurrentLane = currentLane; }

void turboHiker::Hiker::onYelledAt()
{

        bool successful = Random::get().randomNumber() < 0.5;

        if (successful) {
                if (!isMarkedForRemoval()) {
                        markForRemoval();
                }
        }
}
