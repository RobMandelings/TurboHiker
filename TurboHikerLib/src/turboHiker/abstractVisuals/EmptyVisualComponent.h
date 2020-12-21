//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_EMPTYVISUALCOMPONENT_H
#define TURBOHIKER_EMPTYVISUALCOMPONENT_H

#endif // TURBOHIKER_EMPTYVISUALCOMPONENT_H

#include "VisualComponent.h"

namespace turboHiker {

/**
 * A visual component without any implementation on drawing stuff. In other words, this component is used for all
 * GameObjects that are not visualized (invisible)
 */
class EmptyVisualComponent : public VisualComponent
{

public:
        /**
         * Empty draw function: does nothing
         */
        void draw(const Vector2d& worldLocation) const final {}
};
} // namespace turboHiker