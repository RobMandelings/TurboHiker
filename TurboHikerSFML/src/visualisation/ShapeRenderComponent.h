//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_SHAPERENDERCOMPONENT_H
#define TURBOHIKER_SHAPERENDERCOMPONENT_H

#include "RenderComponentSFML.h"
#include "Vector2d.h"
#include "WorldLocation.h"
#include <SFML/Graphics/Shape.hpp>
#include <memory>

namespace turboHikerSFML {
class ShapeRenderComponent : RenderComponentSFML
{

public:
        ShapeRenderComponent(WindowDrawer& windowDrawer, std::unique_ptr<sf::Shape> shape);

        void draw(const turboHiker::Vector2d& worldLocation) const final;

private:

        std::unique_ptr<sf::Shape> mShape;

};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SHAPERENDERCOMPONENT_H
