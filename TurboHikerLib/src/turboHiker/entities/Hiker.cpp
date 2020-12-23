//
// Created by RobMa on 23/12/2020.
//

#include "Hiker.h"

#include "BoundingBox.h"
#include "RenderComponent.h"

turboHiker::Hiker::Hiker(const turboHiker::Vector2d& initialLocation, std::unique_ptr<BoundingBox> boundingBox,
                         std::unique_ptr<RenderComponent> renderComponent, const turboHiker::Vector2d& initialVelocity)
    : MovableEntity(initialLocation, std::move(boundingBox), std::move(renderComponent), initialVelocity)
{
}