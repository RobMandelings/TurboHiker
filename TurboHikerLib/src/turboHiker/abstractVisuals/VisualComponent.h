//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_VISUALCOMPONENTSFML_H
#define TURBOHIKER_VISUALCOMPONENT_H

#endif // TURBOHIKER_VISUALCOMPONENTSFML_H

namespace turboHiker {

class Vector2d;

class VisualComponent
{

public:
        virtual void draw(const Vector2d& worldLocation) const = 0;
};
} // namespace turboHiker