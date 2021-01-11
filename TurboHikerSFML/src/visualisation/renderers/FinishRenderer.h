//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_FINISHRENDERER_H
#define TURBOHIKER_FINISHRENDERER_H

#include "SceneNodeRendererSFML.h"
#include <SFML/Graphics/RectangleShape.hpp>

namespace turboHikerSFML {
class FinishRenderer : public turboHikerSFML::SceneNodeRendererSFML
{

public:

        FinishRenderer(turboHiker::DrawableRenderer& windowDrawer, const sf::Vector2f& dimensions);

private:

        std::unique_ptr<Renderer> clone() const override;
        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;
        void render() const override;

private:

        sf::RectangleShape mFinishShape;
        sf::RectangleShape createFinish(const sf::Vector2f& dimensions);
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_FINISHRENDERER_H
