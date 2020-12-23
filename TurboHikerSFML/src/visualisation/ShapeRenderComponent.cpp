//
// Created by RobMa on 23/12/2020.
//

#include "ShapeRenderComponent.h"

#include "SFML/Graphics/Shape.hpp"

turboHikerSFML::ShapeRenderComponent::ShapeRenderComponent(turboHikerSFML::WindowDrawer& windowDrawer,
                                                           std::unique_ptr<sf::Shape> shape) : RenderComponentSFML(windowDrawer), mShape(std::move(shape)) {
}
void turboHikerSFML::ShapeRenderComponent::draw(const turboHiker::Vector2d& worldLocation) const {
        drawOnWindow(*mShape, worldLocation);
}