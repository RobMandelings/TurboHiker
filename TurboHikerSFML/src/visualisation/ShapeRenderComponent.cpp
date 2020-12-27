//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"
#include "Transformation.h"

turboHiker::ShapeRenderComponent::ShapeRenderComponent(DrawableRenderer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape, double speed)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape)), goingDown(false), speed(speed), summedDt(0)
{
}

void turboHiker::ShapeRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                                  const turboHiker::Vector2d& currentWorldLocation)
{

        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);


        mShape->setPosition(float(pixelCoordinates.x), float(pixelCoordinates.y));

        if (mShape->getFillColor().r == 255) {
                goingDown = true;
        } else if (mShape->getFillColor().r == 0) {
                goingDown = false;
        }

        // One second has passed
        mShape->setFillColor(sf::Color(mShape->getFillColor().r + int((goingDown ? -1 : 1) * speed * dt.count()),
                                       mShape->getFillColor().g, mShape->getFillColor().b));
        summedDt = 0;
}

void turboHiker::ShapeRenderComponent::render() const { renderOnWindow(*mShape); }