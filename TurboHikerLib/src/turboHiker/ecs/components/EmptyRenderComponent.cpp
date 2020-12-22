//
// Created by RobMa on 22/12/2020.
//

#include "EmptyRenderComponent.h"

turboHiker::EmptyRenderComponent::EmptyRenderComponent(const turboHiker::WorldPosition& worldPosition)
    : RenderComponent(worldPosition)
{
}

void turboHiker::EmptyRenderComponent::draw() const {}
