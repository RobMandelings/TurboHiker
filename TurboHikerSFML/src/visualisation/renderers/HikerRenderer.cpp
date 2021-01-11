//
// Created by RobMa on 23/12/2020.
//

#include "HikerRenderer.h"

#include "SFML/Graphics/Shape.hpp"
#include "Transformation.h"

using namespace turboHiker;

turboHikerSFML::HikerRenderer::HikerRenderer(DrawableRenderer& windowRenderer, double animationSpeed,
                                                       float size, sf::Color color)
    : SceneNodeRendererSFML(windowRenderer), mHikerShape(sf::CircleShape(size)),
      mCurrentColor(0, 0, 0), goingDown(false), mSpeed(animationSpeed),
      summedDt(0)
{
        mHikerShape.setFillColor(color);
        mHikerShape.setOrigin(mHikerShape.getGlobalBounds().width / 2, mHikerShape.getGlobalBounds().height / 2);
        mCurrentColor.setColor(color);
}

std::unique_ptr<Renderer> turboHikerSFML::HikerRenderer::clone() const
{
        return std::make_unique<HikerRenderer>(*this);
}

void turboHikerSFML::HikerRenderer::update(const turboHiker::Updatable::seconds& dt,
                                              const turboHiker::Vector2d& currentWorldLocation)
{

        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

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

void turboHikerSFML::HikerRenderer::render() const { renderOnWindow(mHikerShape); }