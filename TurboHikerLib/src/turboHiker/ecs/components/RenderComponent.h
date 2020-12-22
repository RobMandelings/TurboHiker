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
        RenderComponent(const WorldPosition& worldPosition, std::unique_ptr<Model> model);
        virtual void draw() const;

private:
        /**
         * Keeps track of the position that is maintained and updated by a PhysicsComponent (Aggregation, not owned by the
         * RenderComponent)
         */
        const WorldPosition& mWorldPosition;
        std::unique_ptr<Model> mModel;
};
} // namespace turboHiker