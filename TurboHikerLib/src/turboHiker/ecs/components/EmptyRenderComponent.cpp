//
// Created by RobMa on 22/12/2020.
//

#include "EmptyRenderComponent.h"

turboHiker::EmptyRenderComponent::EmptyRenderComponent(const turboHiker::WorldLocation& worldPosition)
    : RenderComponent(worldPosition)
{
}

void turboHiker::EmptyRenderComponent::draw(const WorldLocation& worldLocation) const {}
