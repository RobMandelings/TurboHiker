//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"
#include "Transformation.h"

turboHiker::ShapeRenderComponent::ShapeRenderComponent(DrawableRenderer& windowDrawer, std::unique_ptr<sf::Shape> shape,
                                                       double speed)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape)),
      mCurrentColor(mShape->getFillColor().r / 255.0, mShape->getFillColor().g / 255.0, mShape->getFillColor().b / 255.0),
      goingDown(false), mSpeed(speed), summedDt(0)
{
}

void turboHiker::ShapeRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                              const turboHiker::Vector2d& currentWorldLocation)
{

        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

        mShape->setPosition(float(pixelCoordinates.x), float(pixelCoordinates.y));

        if (mCurrentColor.getRed() == 1) {
                goingDown = true;
        } else if (mCurrentColor.getRed() == 0) {
                goingDown = false;
        }

        if (mSpeed > 0) {
                mCurrentColor.setRed(mCurrentColor.getRed() + (goingDown ? -1 : 1) * mSpeed * dt.count());
        }

        // One second has passed
        mShape->setFillColor(mCurrentColor.getSFMLColor());
        summedDt = 0;
}

void turboHiker::ShapeRenderComponent::render() const { renderOnWindow(*mShape); }