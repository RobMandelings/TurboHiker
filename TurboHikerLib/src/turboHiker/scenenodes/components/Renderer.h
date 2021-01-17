//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <memory>
#include <turboHiker/interfaces/Updatable.h>
#include <turboHiker/utils/maths/Vector2d.h>
#include <cassert>

namespace turboHiker {

class SceneNode;

/**
 * The renderer is an abstract class used to render SceneNodes. The specific visual implementation is not done here.
 */
template <typename RenderedObject>
class Renderer
{

public:
        Renderer() = default;

        virtual ~Renderer() = default;

        /**
         * Clones the render component
         * @return the cloned render component
         */
        virtual std::unique_ptr<Renderer<SceneNode>> clone() const = 0;

        template<typename DerivedRenderedObject>
        Renderer<RenderedObject>& operator=(const Renderer<DerivedRenderedObject>& derived) {
                assert(std::dynamic_pointer_cast<Renderer<RenderedObject>>(derived.getRenderedObject()));
                mRenderedObject = std::static_pointer_cast<Renderer<RenderedObject>>(derived.getRenderedObject());
                return *this;
        }

        void setRenderedObject(const RenderedObject& renderedObject) { mRenderedObject = renderedObject; }

        /**
         * Updates the Renderer to do updates based on deltaTime or state of the sceneNode or just update the
         * location of where the image should be drawn
         * @param dt: the timestep (in seconds) by which time has passed
         * @param currentWorldLocation: the location of the Type corresponding to this Renderer
         */
        virtual void update(const Updatable::seconds& dt, const Vector2d& currentWorldLocation) = 0;

        /**
         * Renders the Type that holds this Renderer. How it is visualised or rendered is specific to the
         * visualisation library you use (Such as SFML)
         */
        virtual void render() const = 0;

        const std::shared_ptr<RenderedObject>& getRenderedObject() const
        {
                assert(mRenderedObject.lock() != nullptr &&
                       "Object is removed but renderer still alive, this should not be possible");
                return mRenderedObject.lock();
        }

private:
        std::weak_ptr<RenderedObject> mRenderedObject;
};
} // namespace turboHiker