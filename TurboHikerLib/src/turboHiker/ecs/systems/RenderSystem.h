//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>

namespace turboHiker {

class WorldPosition;
class Model;

class RenderSystem
{

public:

        virtual void render() = 0;

private:

        /**
         * Keeps track of the position that is maintained and updated by a PhysicsSystem (Aggregation, not owned by the RenderSystem)
         */
        const WorldPosition& mWorldPosition;
        std::shared_ptr<Model> mModel;

};
}