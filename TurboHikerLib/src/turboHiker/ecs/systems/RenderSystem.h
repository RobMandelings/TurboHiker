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
        RenderSystem(const WorldPosition& worldPosition, std::shared_ptr<Model>  model);
        virtual void render() const;

private:

        /**
         * Keeps track of the position that is maintained and updated by a PhysicsSystem (Aggregation, not owned by the RenderSystem)
         */
        const WorldPosition& mWorldPosition;
        std::unique_ptr<Model> mModel;

};
}