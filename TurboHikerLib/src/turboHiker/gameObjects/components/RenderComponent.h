//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

namespace turboHiker {

class WorldLocation;
class Model;

class RenderComponent
{

public:

        virtual void draw(const WorldLocation& worldLocation) const = 0;
};
} // namespace turboHiker