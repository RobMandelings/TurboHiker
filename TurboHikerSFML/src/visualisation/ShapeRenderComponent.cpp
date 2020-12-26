//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "Transformation.h"
#include "SFML/Graphics/Shape.hpp"

turboHikerSFML::ShapeRenderComponent::ShapeRenderComponent(DrawableRenderer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape, double speed)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape)), goingDown(false), speed(speed), summedDt(0)
{
}

void turboHikerSFML::ShapeRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                                  const turboHiker::Vector2d& currentWorldLocation)
{

        const turboHiker::Vector2d worldViewCenter = Transformation::get().getWorldView().getWorldViewCenter();

        Transformation::get().getWorldView().setWorldViewCenter(turboHiker::Vector2d(worldViewCenter.x + 0.1 + dt.count(), worldViewCenter.y + 2 * dt.count()));

        sf::Vector2f pixelCoordinates = Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

        mShape->setPosition(pixelCoordinates.x - mShape->getGlobalBounds().width / 2, pixelCoordinates.y - mShape->getGlobalBounds().height / 2);

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

void turboHikerSFML::ShapeRenderComponent::render() const { renderOnWindow(*mShape); }