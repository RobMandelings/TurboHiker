//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "EmptyRenderComponent.h"
#include "InputComponent.h"
#include "MovingPhysicsComponent.h"
#include "CollisionComponent.h"
#include "BoundingBox.h"
#include "Vector2d.h"
#include "Entity.h"
#include <memory>

using namespace turboHiker;


std::unique_ptr<Entity> turboHikerSFML::EntityFactorySFML::createStaticHiker(const Vector2d& location) const
{

        std::unique_ptr<CollisionComponent> collisionComponent = std::make_unique<CollisionComponent>(BoundingBox(0, 0, 0, 0));
        // Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent =
            std::make_unique<MovingPhysicsComponent>(location, std::move(collisionComponent), Vector2d(0.0, 0.0));
        std::unique_ptr<InputComponent> inputComponent = std::make_unique<InputComponent>();
        std::unique_ptr<EmptyRenderComponent> renderComponent = std::make_unique<EmptyRenderComponent>();

        return std::make_unique<Entity>(std::move(movingPhysicsComponent), std::move(inputComponent), std::move(renderComponent));

}