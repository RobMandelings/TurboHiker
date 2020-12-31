//
// Created by RobMa on 23/12/2020.
//

#include "HikerRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"
#include "Transformation.h"

using namespace turboHiker;

turboHiker::HikerRenderComponent::HikerRenderComponent(DrawableRenderer& windowRenderer, double animationSpeed,
                                                       float size,
                                                       sf::Color color)
    : RenderComponentSFML(windowRenderer), mHikerShape(sf::CircleShape(size)),
      mCurrentColor(mHikerShape.getFillColor().r / 255.0, mHikerShape.getFillColor().g / 255.0,
                    mHikerShape.getFillColor().b / 255.0),
      goingDown(false), mSpeed(animationSpeed), summedDt(0)
{
        mHikerShape.setFillColor(color);
        mHikerShape.setOrigin(mHikerShape.getGlobalBounds().width / 2, mHikerShape.getGlobalBounds().height / 2);
}

std::unique_ptr<RenderComponent> turboHiker::HikerRenderComponent::clone()
{
        return std::make_unique<HikerRenderComponent>(*this);
}

void turboHiker::HikerRenderComponent::update(const turboHiker::Updatable::seconds& dt,
                                              const turboHiker::Vector2d& currentWorldLocation)
{


        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

        std::cout << "JepJep: " << pixelCoordinates << std::endl;

        mHikerShape.setPosition(float(pixelCoordinates.x), float(pixelCoordinates.y));

        if (mCurrentColor.getRed() == 1) {
                goingDown = true;
        } else if (mCurrentColor.getRed() == 0) {
                goingDown = false;
        }

        if (mSpeed > 0) {
                mCurrentColor.setRed(mCurrentColor.getRed() + (goingDown ? -1 : 1) * mSpeed * dt.count());
        }

        // One second has passed
        mHikerShape.setFillColor(mCurrentColor.getSFMLColor());
        summedDt = 0;
}

void turboHiker::HikerRenderComponent::render() const { renderOnWindow(mHikerShape);
}