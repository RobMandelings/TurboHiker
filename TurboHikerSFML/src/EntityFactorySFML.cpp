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
#include "MovableEntity.h"
#include <memory>
#include "SFML/Graphics/CircleShape.hpp"

using namespace turboHiker;

turboHikerSFML::EntityFactorySFML::EntityFactorySFML(turboHikerSFML::WindowRenderer& mWindowDrawer)
    : mWindowDrawer(mWindowDrawer)
{
}

std::unique_ptr<Entity> turboHikerSFML::EntityFactorySFML::createTestCircle(const Vector2d& location,
                                                                            const Vector2d& initialVelocity) const
{

        std::unique_ptr<sf::Shape> shape = std::make_unique<sf::CircleShape>(50.0f);
        shape->setFillColor(sf::Color(100, 0, 0));

        std::unique_ptr<ShapeRenderComponent> shapeRenderComponent = std::make_unique<ShapeRenderComponent>(mWindowDrawer, std::move(shape));

        return std::make_unique<MovableEntity>(Vector2d(50, 50), nullptr, std::move(shapeRenderComponent), Vector2d(5, 25));

}
