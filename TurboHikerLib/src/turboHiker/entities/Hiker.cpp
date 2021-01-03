//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include <turboHiker/Category.h>

#include "BoundingBox.h"
#include "Random.h"
#include "SceneNodeRenderer.h"
#include "Transformation.h"

turboHiker::Hiker::Hiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
                         std::unique_ptr<SceneNodeRenderer> renderComponent, const Vector2d& initialVelocity,
                         bool playerControlled, const std::string& name)
    : Entity(initialLocation, boundingSize, std::move(renderComponent), initialVelocity, name),
      mPlayerControlled(playerControlled)
{
}

unsigned int turboHiker::Hiker::getCategory() const
{
        return mPlayerControlled ? Category::PlayerHiker : Category::Hiker;
}
int turboHiker::Hiker::getCurrentLane() const { return mCurrentLane; }
void turboHiker::Hiker::setCurrentLane(int currentLane) { mCurrentLane = currentLane; }
bool turboHiker::Hiker::isPlayerControlled() const { return mPlayerControlled; }

void turboHiker::Hiker::onYelledAt()
{

        bool successful = Random::get().randomNumber() < 0.5;

        if (successful) {
                if (!isMarkedForRemoval()) {
                        markForRemoval();
                }
        }
}
