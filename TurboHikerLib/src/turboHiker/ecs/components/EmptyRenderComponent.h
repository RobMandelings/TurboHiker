//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_EMPTYRENDERCOMPONENT_H
#define TURBOHIKER_EMPTYRENDERCOMPONENT_H

#include "RenderComponent.h"

namespace turboHiker {

/**
 * This class is used for invisible entities
 */
class EmptyRenderComponent : RenderComponent
{

public:
        EmptyRenderComponent(const WorldLocation& worldPosition);
private:
        void draw(const WorldLocation& worldLocation) const override;
};
}

#endif // TURBOHIKER_EMPTYRENDERCOMPONENT_H
