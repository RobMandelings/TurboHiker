//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

namespace turboHiker {

class Vector2d;

class Model
{

public:

        virtual void draw(const Vector2d& worldLocation) const = 0;

};
} // namespace turboHiker
