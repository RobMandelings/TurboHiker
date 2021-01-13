//
// Created by RobMa on 20/12/2020.
//

#include "Removable.h"

#include <cassert>

namespace turboHiker {

Removable::Removable() : mMarkedForRemoval(false) {}

void Removable::markForRemoval()
{
        mMarkedForRemoval = true;
}
bool Removable::isMarkedForRemoval() const { return mMarkedForRemoval; }
} // namespace turboHiker