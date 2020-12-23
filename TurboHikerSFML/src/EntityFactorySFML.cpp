//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "EmptyRenderComponent.h"
#include "InputComponent.h"
#include "MovingPhysicsComponent.h"
#include "BoundingBox.h"
#include "Vector2d.h"
#include "Entity.h"
#include <memory>

using namespace turboHiker;

std::unique_ptr<Entity> EntityFactorySFML::createStaticHiker(const WorldLocation& worldLocation) const
{
        // Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent =
            std::make_unique<MovingPhysicsComponent>(worldLocation, BoundingBox(0, 0, 0, 0), Vector2d(0.0, 0.0));
        std::unique_ptr<InputComponent> inputComponent = std::make_unique<InputComponent>();
        std::unique_ptr<EmptyRenderComponent> renderComponent = std::make_unique<EmptyRenderComponent>();

        return std::make_unique<Entity>(std::move(movingPhysicsComponent), std::move(inputComponent), std::move(renderComponent));

}