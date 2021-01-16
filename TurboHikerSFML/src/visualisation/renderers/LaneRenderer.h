//
// Created by RobMa on 1/01/2021.
//

#ifndef TURBOHIKER_LANERENDERER_H
#define TURBOHIKER_LANERENDERER_H

#include "SceneNodeRendererSFML.h"
#include <SFML/Graphics/RectangleShape.hpp>

namespace turboHikerSFML {
class LaneRenderer : public turboHikerSFML::SceneNodeRendererSFML
{

public:
        LaneRenderer(turboHiker::DrawableRenderer& windowDrawer, const sf::Vector2f& dimensions);
private:

        /**
         * Clones the Renderer
         */
        std::unique_ptr<Renderer> clone() const override;

        /**
         * See Renderer
         */
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        /**
         * See Renderer
         */
        void render() const override;

        /**
         * Creates the lane base shape
         * @param laneDimensions: the dimensions in pixels
         * @return the created object
         */
        sf::RectangleShape createLane(const sf::Vector2f& laneDimensions);

        /**
         * Creates the left border of the lane
         * @param laneDimensions: the dimensions in pixels
         * @return the created object
         */
        sf::RectangleShape createLeftBorder(const sf::Vector2f& laneDimensions);

        /**
         * Creates the right border of the lane
         * @param laneDimensions: the dimensions in pixels
         * @return the created object
         */
        sf::RectangleShape createRightBorder(const sf::Vector2f& laneDimensions);

private:

        /**
         * Shape representing the base of the lane
         */
        sf::RectangleShape mLane;

        /**
         * Shape representing the left border of the lane
         */
        sf::RectangleShape mLeftBorder;

        /**
         * Shape representing the right border of the lane
         */
        sf::RectangleShape mRightBorder;
};
} // namespace turboHiker

#endif // TURBOHIKER_LANERENDERER_H
