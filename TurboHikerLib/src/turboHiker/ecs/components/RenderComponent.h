//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

namespace turboHiker {

class WorldPosition;
class Model;

class RenderComponent
{

public:
        explicit RenderComponent(const WorldPosition& worldPosition);
        virtual void draw() const = 0;

        /**
         * Keeps track of the position that is maintained and updated by a PhysicsComponent (Aggregation, not owned by the
         * RenderComponent)
         */
        const WorldPosition& mWorldPosition;
};
} // namespace turboHiker