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
        std::unique_ptr<SceneNodeRenderer> clone() override;
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;
        void render() const override;

        sf::RectangleShape createLane(const sf::Vector2f& laneDimensions);
        sf::RectangleShape createLeftBorder(const sf::Vector2f& laneDimensions);
        sf::RectangleShape createRightBorder(const sf::Vector2f& laneDimensions);

private:

        sf::RectangleShape mLane;
        sf::RectangleShape mLeftBorder;
        sf::RectangleShape mRightBorder;
};
} // namespace turboHiker

#endif // TURBOHIKER_LANERENDERER_H
