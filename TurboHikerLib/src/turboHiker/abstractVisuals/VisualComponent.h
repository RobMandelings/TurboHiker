//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_VISUALCOMPONENTSFML_H
#define TURBOHIKER_VISUALCOMPONENT_H

#endif // TURBOHIKER_VISUALCOMPONENTSFML_H

namespace turboHiker {

class Vector2d;

/**
 * The VisualComponent is used by the Entity to (optionally) give it a visual representation.
 * Visual libraries can inherit from this base VisualComponent class to actually give it a visual representation in the
 * API of the visualization library (Such as SFML, Qt,...)
 */
class VisualComponent
{

public:
        virtual void draw(const Vector2d& worldLocation) const = 0;
};
} // namespace turboHiker