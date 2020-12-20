//
// Created by RobMa on 20/12/2020.
//

#include "Removable.h"

#include <cassert>

namespace turboHiker {
void Removable::markForRemoval()
{
        assert(!isMarkedForRemoval() && "Object is already marked for removal");
        mMarkedForRemoval = true;
}
bool Removable::isMarkedForRemoval() const { return mMarkedForRemoval; }
} // namespace turboHiker