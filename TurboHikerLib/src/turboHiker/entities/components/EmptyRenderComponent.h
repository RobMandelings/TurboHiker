//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_EMPTYRENDERCOMPONENT_H
#define TURBOHIKER_EMPTYRENDERCOMPONENT_H

#include "RenderComponent.h"
#include <turboHiker/utils/maths/Vector2d.h>

namespace turboHiker {

/**
 * This class is used for invisible entities
 */
class EmptyRenderComponent : public RenderComponent
{
public:
        void update(const Updatable::seconds& dt, const Vector2d& worldLocation) override;

        void render() const override;
};
}

#endif // TURBOHIKER_EMPTYRENDERCOMPONENT_H
