//
// Created by Rob Mandelings on 22/12/2020.
//

#include "RenderComponent.h"

#include "WorldPosition.h"
#include <utility>

turboHiker::RenderComponent::RenderComponent(const WorldPosition& worldPosition)
    : mWorldPosition(worldPosition)
{
}

/**
 * Simple Render implementation just consists of getting the world Position as well as the model and delegating the draw
 * request to that model
 */