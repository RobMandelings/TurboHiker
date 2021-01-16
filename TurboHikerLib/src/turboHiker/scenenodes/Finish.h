//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_FINISH_H
#define TURBOHIKER_FINISH_H

#endif // TURBOHIKER_FINISH_H

#include "SceneNode.h"

namespace turboHiker {
class Finish : public SceneNode
{

public:
        /**
         * Simple constructor
         * @param span: what the finish 'spans' on the world coordinates: left, bottom, width, height. The initial
         * location and size is deduced from this span.
         */
        Finish(const BoundingBox& span);
        unsigned int getCategory() const override;
};
} // namespace turboHiker