//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>
#include <turboHiker/interfaces/Updatable.h>
#include <turboHiker/utils/maths/Vector2d.h>

namespace turboHiker {

class WorldLocation;
class Model;

class SceneNodeRenderer
{

public:

        /**
         * Clones the render component
         * @return the cloned render component
         */
        virtual std::unique_ptr<SceneNodeRenderer> clone() = 0;
        /**
         * Updates the SceneNodeRenderer to do updates based on deltaTime or state of the sceneNode or just update the
         * location of where the image should be drawn
         * @param dt: the timestep (in seconds) by which time has passed
         * @param currentWorldLocation: the location of the SceneNode corresponding to this SceneNodeRenderer
         */
        virtual void update(const Updatable::seconds& dt, const Vector2d& currentWorldLocation) = 0;

        /**
         * Renders the SceneNode that holds this SceneNodeRenderer. How it is visualised or rendered is specific to the
         * visualisation library you use (Such as SFML)
         */
        virtual void render() const = 0;

        virtual ~SceneNodeRenderer() = default;
};
} // namespace turboHiker