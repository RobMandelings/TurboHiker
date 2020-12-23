//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_SHAPERENDERCOMPONENT_H
#define TURBOHIKER_SHAPERENDERCOMPONENT_H

#include "RenderComponentSFML.h"
#include <SFML/Graphics/Shape.hpp>
#include <memory>

namespace turboHiker {
class Vector2d;
class WorldLocation;
} // namespace turboHiker

namespace turboHikerSFML {
class ShapeRenderComponent : public RenderComponentSFML
{

public:
        ShapeRenderComponent(WindowRenderer& windowDrawer, std::unique_ptr<sf::Shape> shape);

        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        void render() const final;

private:
        std::unique_ptr<sf::Shape> mShape;

        bool goingDown;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SHAPERENDERCOMPONENT_H
