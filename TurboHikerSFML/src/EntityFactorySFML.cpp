//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "EmptyRenderComponent.h"
#include "InputComponent.h"
#include "MovingPhysicsComponent.h"
#include "BoundingBox.h"
#include "Vector2d.h"
#include <memory>

using namespace turboHiker;

Entity* EntityFactorySFML::createStaticHiker(const WorldLocation& worldLocation) const
{
        /*// Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent =
            std::make_unique<MovingPhysicsComponent>(worldLocation, BoundingBox(0, 0, 0, 0), Vector2d(0.0, 0.0));
        std::unique_ptr<InputComponent> inputComponent = std::make_unique<InputComponent>();
        const WorldLocation& worldPosition1 = movingPhysicsComponent->getWorldLocation();
        std::unique_ptr<EmptyRenderComponent> renderComponent = EmptyRenderComponent();*/

}