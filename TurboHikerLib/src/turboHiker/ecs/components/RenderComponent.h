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
        explicit RenderComponent(const WorldLocation& worldPosition);
        virtual void draw() const = 0;

        /**
         * Keeps track of the position that is maintained and updated by a PhysicsComponent (Aggregation, not owned by the
         * RenderComponent)
         */
        const WorldLocation& mWorldPosition;
};
} // namespace turboHiker