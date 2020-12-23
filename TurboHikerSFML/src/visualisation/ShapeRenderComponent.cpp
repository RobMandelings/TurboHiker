//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"

turboHikerSFML::ShapeRenderComponent::ShapeRenderComponent(turboHikerSFML::WindowRenderer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape)), goingDown(false)
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

        mShape->setFillColor(sf::Color(mShape->getFillColor().r + (goingDown ? -1 : 1), mShape->getFillColor().g, mShape->getFillColor().b));
}

void turboHikerSFML::ShapeRenderComponent::render() const
{
        renderOnWindow(*mShape);
}