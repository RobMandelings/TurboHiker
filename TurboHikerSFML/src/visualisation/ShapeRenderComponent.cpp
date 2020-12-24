//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"

turboHikerSFML::ShapeRenderComponent::ShapeRenderComponent(DrawableRenderer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape, double speed)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape)), goingDown(false), speed(speed), summedDt(0)
{
}

void turboHikerSFML::ShapeRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                                  const turboHiker::Vector2d& currentWorldLocation)
{

        mShape->setPosition(float(currentWorldLocation.x), float(currentWorldLocation.y));

        if (mShape->getFillColor().r == 255) {
                goingDown = true;
        } else if (mShape->getFillColor().r == 0) {
                goingDown = false;
        }

        std::cout << int((goingDown ? -1 : 1) * speed) << std::endl;

        // One second has passed
        mShape->setFillColor(sf::Color(mShape->getFillColor().r + int((goingDown ? -1 : 1) * speed * dt.count()),
                                       mShape->getFillColor().g, mShape->getFillColor().b));
        summedDt = 0;
}

void turboHikerSFML::ShapeRenderComponent::render() const { renderOnWindow(*mShape); }