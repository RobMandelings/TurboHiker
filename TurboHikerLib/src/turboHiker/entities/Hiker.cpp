//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"
#include <turboHiker/Category.h>

#include "BoundingBox.h"
#include "RenderComponent.h"

turboHiker::Hiker::Hiker(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> boundingBox,
                         std::unique_ptr<RenderComponent> renderComponent, const Vector2d& initialVelocity,
                         bool playerControlled)
    : MovableEntity(initialLocation, std::move(boundingBox), std::move(renderComponent), initialVelocity),
      mPlayerControlled(playerControlled)
{
}

unsigned int turboHiker::Hiker::getCategory() const
{
        return mPlayerControlled ? Category::PlayerHiker : Category::Hiker;
}