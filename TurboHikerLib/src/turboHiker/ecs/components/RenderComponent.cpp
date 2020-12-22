//
// Created by Rob Mandelings on 22/12/2020.
//

#include "RenderComponent.h"

#include "Model.h"
#include "WorldPosition.h"
#include <utility>

turboHiker::RenderComponent::RenderComponent(const turboHiker::WorldPosition& worldPosition, std::unique_ptr<Model> model)
    : mWorldPosition(worldPosition), mModel(std::move(model))
{
}

/**
 * Simple Render implementation just consists of getting the world Position as well as the model and delegating the draw
 * request to that model
 */
void turboHiker::RenderComponent::draw() const { mModel->draw(mWorldPosition.getVectorPosition()); }