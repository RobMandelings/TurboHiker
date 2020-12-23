//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "EmptyRenderComponent.h"
#include "InputComponent.h"
#include "MovingPhysicsComponent.h"
#include "CollisionComponent.h"
#include "ShapeRenderComponent.h"
#include "BoundingBox.h"
#include "Vector2d.h"
#include "Entity.h"
#include <memory>
#include "SFML/Graphics/CircleShape.hpp"

using namespace turboHiker;

turboHikerSFML::EntityFactorySFML::EntityFactorySFML(turboHikerSFML::WindowDrawer& mWindowDrawer)
    : mWindowDrawer(mWindowDrawer)
{
}

std::unique_ptr<Entity> turboHikerSFML::EntityFactorySFML::createTestCircle(const Vector2d& location,
                                                                            const Vector2d& initialVelocity) const
{

        std::unique_ptr<CollisionComponent> collisionComponent = std::make_unique<CollisionComponent>(BoundingBox(0, 0, 0, 0));
        // Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent =
            std::make_unique<MovingPhysicsComponent>(location, std::move(collisionComponent), Vector2d(initialVelocity.x, initialVelocity.y));
        std::unique_ptr<InputComponent> inputComponent = std::make_unique<InputComponent>();

        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(50.0f);
        shape->setFillColor(sf::Color(100, 0, 0));

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent = std::make_unique<ShapeRenderComponent>(mWindowDrawer, std::move(shape));

        return std::make_unique<Entity>(std::move(movingPhysicsComponent), std::move(inputComponent), std::move(shapeRenderComponent));

}
