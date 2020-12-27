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

// TODO rezie shape depending on the current viewHeight and width.
class ShapeRenderComponent : public RenderComponentSFML
{

public:
        ShapeRenderComponent(DrawableRenderer& windowDrawer, std::unique_ptr<sf::Shape> shape, double speed);

        void update(const turboHiker::Updatable::seconds& dt,
                    const turboHiker::Vector2d& currentWorldLocation) override;

        void render() const final;

private:
        std::unique_ptr<sf::Shape> mShape;

        bool goingDown;
        double speed;
        double summedDt;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SHAPERENDERCOMPONENT_H
