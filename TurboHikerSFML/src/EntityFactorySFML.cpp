//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "turboHiker/ecs/components/MovingPhysicsComponent.h"
#include "turboHiker/ecs/components/InputComponent.h"
#include "turboHiker/ecs/components/EmptyRenderComponent.h"
#include "turboHiker/ecs/modules/physics/BoundingBox.h"
#include "turboHiker/utils/maths/Vector2d.h"
#include <memory>

using namespace turboHiker;

Entity* EntityFactorySFML::createStaticHiker(const WorldPosition& worldPosition) const
{
        // Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent =
            std::make_unique<MovingPhysicsComponent>(worldPosition, BoundingBox(0, 0, 0, 0), Vector2d(0.0, 0.0));
        std::unique_ptr<InputComponent> inputComponent = std::make_unique<InputComponent>();
        const WorldPosition& worldPosition1 = movingPhysicsComponent->getWorldPosition();
        std::unique_ptr<EmptyRenderComponent> renderComponent = EmptyRenderComponent(movingPhysicsComponent->getWorldPosition());

}