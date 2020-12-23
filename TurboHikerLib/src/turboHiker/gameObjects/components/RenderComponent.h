//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>
#include <turboHiker/utils/maths/Vector2d.h>

namespace turboHiker {

class WorldLocation;
class Model;

class RenderComponent
{

public:

        virtual void draw(const Vector2d& worldLocation) const = 0;
};
} // namespace turboHiker