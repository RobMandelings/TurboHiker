//
// Created by RobMa on 1/01/2021.
//

#include "LaneRenderer.h"
#include "Transformation.h"
#include <cassert>

using namespace turboHiker;

turboHikerSFML::LaneRenderer::LaneRenderer(DrawableRenderer& windowDrawer, const sf::Vector2f& dimensions)
    : SceneNodeRendererSFML(windowDrawer)
{
        mLane = createLane(dimensions);
        mLeftBorder = createLeftBorder(dimensions);
        //mRightBorder = createRightBorder(dimensions);
}

std::unique_ptr<Renderer<SceneNode>> turboHikerSFML::LaneRenderer::clone() const
{
        return std::make_unique<LaneRenderer>(*this);
}
void turboHikerSFML::LaneRenderer::update(const turboHiker::Updatable::seconds& dt,
                                          const turboHiker::Vector2d& currentWorldLocation)
{

        Vector2d pixelCoordinates =
            Transformation::get().convertWorldCoordinatesToPixelCoordinates(currentWorldLocation);

        sf::Vector2f pixelCoordinates2f(pixelCoordinates.x, pixelCoordinates.y);

        mLane.setPosition(pixelCoordinates2f.x, pixelCoordinates2f.y);
        mLeftBorder.setPosition(pixelCoordinates2f.x, pixelCoordinates2f.y);
        mRightBorder.setPosition(pixelCoordinates2f.x, pixelCoordinates2f.y);

}
void turboHikerSFML::LaneRenderer::render() const
{
        renderOnWindow(mLane);
        renderOnWindow(mLeftBorder);
        renderOnWindow(mRightBorder);
}

sf::RectangleShape turboHikerSFML::LaneRenderer::createLane(const sf::Vector2f& laneDimensions)
{

        sf::RectangleShape lane = sf::RectangleShape(laneDimensions);
        lane.setOrigin(lane.getGlobalBounds().width / 2, lane.getGlobalBounds().height / 2);
        lane.setFillColor(sf::Color(50, 50, 50));
        return lane;
}
sf::RectangleShape turboHikerSFML::LaneRenderer::createLeftBorder(const sf::Vector2f& laneDimensions)
{
        // Lane must be initialized first
        assert(mLane.getSize().x != 0 && mLane.getSize().y != 0);

        sf::RectangleShape leftBorder = sf::RectangleShape(sf::Vector2f(laneDimensions.x / 50, laneDimensions.y));
        leftBorder.setOrigin(mLane.getGlobalBounds().width / 2, mLane.getGlobalBounds().height / 2);
        leftBorder.setFillColor(sf::Color::Red);

        return leftBorder;
}
sf::RectangleShape turboHikerSFML::LaneRenderer::createRightBorder(const sf::Vector2f& laneDimensions)
{
        // Lane must be initialized first
        assert(mLane.getSize().x != 0 && mLane.getSize().y != 0);

        sf::RectangleShape rightBorder = sf::RectangleShape(sf::Vector2f(laneDimensions.x / 50, laneDimensions.y));
        mRightBorder.setOrigin(-mLane.getGlobalBounds().width / 2, mLane.getGlobalBounds().height / 2);
        ;
        rightBorder.setFillColor(sf::Color::Red);

        return rightBorder;
}
