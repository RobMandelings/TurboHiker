//
// Created by RobMa on 4/01/2021.
//

#include "FinishRenderer.h"
#include "Transformation.h"

using namespace turboHiker;

turboHikerSFML::FinishRenderer::FinishRenderer(DrawableRenderer& windowDrawer, const sf::Vector2f& dimensions)
    : SceneNodeRendererSFML(windowDrawer)
{
        mFinishShape = createFinish(dimensions);
}

std::unique_ptr<Renderer> turboHikerSFML::FinishRenderer::clone() const
{
        return std::make_unique<FinishRenderer>(*this);
}
void turboHikerSFML::FinishRenderer::update(const turboHiker::Updatable::seconds& dt,
                                          const turboHiker::Vector2d& currentWorldLocation)
{

        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

        sf::Vector2f pixelCoordinates2f(pixelCoordinates.x, pixelCoordinates.y);

        mFinishShape.setPosition(pixelCoordinates2f.x, pixelCoordinates2f.y);

}
void turboHikerSFML::FinishRenderer::render() const
{
        renderOnWindow(mFinishShape);
}
sf::RectangleShape turboHikerSFML::FinishRenderer::createFinish(const sf::Vector2f& dimensions)
{

        sf::RectangleShape finishShape = sf::RectangleShape(dimensions);
        finishShape.setOrigin(finishShape.getGlobalBounds().width / 2, finishShape.getGlobalBounds().height / 2);
        finishShape.setFillColor(sf::Color(0, 100, 0, 100));

        return finishShape;
}
