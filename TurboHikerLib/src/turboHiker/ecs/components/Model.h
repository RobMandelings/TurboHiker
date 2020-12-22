//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

namespace turboHiker {

class Position;

class Model
{

        virtual void draw(const Position& worldLocation) const = 0;

};
} // namespace turboHiker
