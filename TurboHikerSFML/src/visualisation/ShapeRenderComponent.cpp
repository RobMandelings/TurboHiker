//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"

turboHikerSFML::ShapeRenderComponent::ShapeRenderComponent(turboHikerSFML::WindowRenderer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape)
    : RenderComponentSFML(windowDrawer), mShape(std::move(shape))
{
}
void turboHikerSFML::ShapeRenderComponent::render(const turboHiker::Vector2d& worldLocation) const
{
        mShape->setFillColor(
            sf::Color(mShape->getFillColor().r == 255 ? mShape->getFillColor().r - 255 : mShape->getFillColor().r + 1,
                      mShape->getFillColor().g == 255 ? mShape->getFillColor().g - 255 : mShape->getFillColor().g + 2,
                      mShape->getFillColor().b == 255 ? mShape->getFillColor().b - 255 : mShape->getFillColor().b + 3));
        drawOnWindow(*mShape, worldLocation);
}