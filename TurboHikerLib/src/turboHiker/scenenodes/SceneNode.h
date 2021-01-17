//
// Created by RobMa on 19/12/2020.
//

#pragma once

#include "Commandable.h"
#include "Removable.h"
#include "Renderable.h"
#include "Renderer.h"
#include "Updatable.h"
#include "Vector2d.h"

#include <memory>
#include <set>
#include <vector>

namespace turboHiker {

class BoundingBox;
class Command;
class Vector2d;

/**
 * Fundamental object to the game. Ranges from simple decorations
 */

class SceneNode : public Updatable, public Renderable, public Commandable, public Removable
{

public:
        /**
         * Simple constructor
         * @param location: initial location of the scene node
         * @param size: the size of the sceneNode, in world coordinates
         * @param name: the name of the Type
         */
        SceneNode(const Vector2d& location, const Vector2d& size, std::string name);

        /**
         * Simple copy constructor. Makes sure that the renderer is copied as well
         * @param other: the other sceneNode
         */
        SceneNode(const SceneNode& other);

        /**
         * Updates the sceneNode accordingly
         * @param dt: the time step to update the Type with
         */
        void update(seconds dt) override;

        /**
         * Updates the render component of this Type
         * @param dt: the time step to update the render component with
         */
        void updateRenderComponent(seconds dt) const;

        /**
         * Executes the given command (if category matches)
         * @param command: the command to execute
         * @param dt: the timestep given with the command to execute time-based commands
         */
        void onCommand(const Command& command, seconds dt) final;

        /**
         * Renders the sceneNode
         */
        void render() const final;

        /**
         * Checks whether or not this Type collides with another Type in the world
         * @param other: the other Type to check for collision
         * @return true if the Type collides with the other Type
         */
        bool collidesWith(const SceneNode& other) const;

        /**
         * Checks whether or not this Type collides with a (custom) boundingBox in the world
         * @param boundingBox: the boundingBox of the Type
         * @return true if the Type collides with the 'boundingBox'
         */
        bool collidesWith(const BoundingBox& boundingBox) const;

        /**
         * Gets the current location of the Type
         * @return a vector pair (x,y) representing the world coordinate
         */
        const Vector2d& getLocation() const;

        /**
         * Simple getter
         * @return the size of the Type
         */
        const Vector2d& getSize() const;

        /**
         * Simple getter
         * @return the name of the Type
         */
        const std::string& getName() const;
        /**
         * Gets the current bounding box of the entity depending on its bounding size and relative to its current
         * location. Used for collision detection. The location is always centered in the middle of the bounding box.
         * @return
         */
        BoundingBox getBoundingBox() const;

        /**
         * Simple getter
         * @return the category of the Type
         */
        virtual unsigned int getCategory() const;

        /**
         * Simple setter
         * @param location: the new location of the Type
         */
        void setLocation(const Vector2d& location);

        /**
         * Simple setter
         * @param size: the size of the Type (in world coordinates)
         */
        void setSize(const Vector2d& size);

        /**
         * Simple setter
         * @param width: the width of the Type
         */
        void setWidth(double width);

        /**
         * Simple setter
         * @param height: the height of the Type
         */
        void setHeight(double height);

        /**
         * Sets the renderer of this Type
         * @param renderer
         */
        template <typename RenderedObject>
        void setRenderer(const Renderer<RenderedObject>& renderer)
        {
                mRenderer = renderer.clone();
                mRenderer->setRenderedObject(*this);
        };

protected:
        /**
         * The location of the Type.
         */
        Vector2d mLocation;

private:
        /**
         * The name of the Type
         */
        std::string mName;

        /**
         * The size of the Type
         */
        Vector2d mSize;

        /**
         * Used to render the Type.
         */
        std::unique_ptr<Renderer<SceneNode>> mRenderer;
};

} // namespace turboHiker