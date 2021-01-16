//
// Created by RobMa on 19/12/2020.
//

#pragma once

#include "Commandable.h"
#include "Removable.h"
#include "Renderable.h"
#include "Updatable.h"
#include "Vector2d.h"
#include "Renderer.h"

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
         * @param name: the name of the SceneNode
         */
        SceneNode(const Vector2d& location, const Vector2d& size, std::string name);

        /**
         * Simple copy constructor. Makes sure that the renderer is copied as well
         * @param other: the other sceneNode
         */
        SceneNode(const SceneNode& other);

        /**
         * Updates the sceneNode accordingly
         * @param dt: the time step to update the SceneNode with
         */
        void update(seconds dt) override;

        /**
         * Updates the render component of this SceneNode
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
         * Checks whether or not this SceneNode collides with another SceneNode in the world
         * @param other: the other SceneNode to check for collision
         * @return true if the SceneNode collides with the other SceneNode
         */
        bool collidesWith(const SceneNode& other) const;

        /**
         * Checks whether or not this SceneNode collides with a (custom) boundingBox in the world
         * @param boundingBox: the boundingBox of the SceneNode
         * @return true if the SceneNode collides with the 'boundingBox'
         */
        bool collidesWith(const BoundingBox& boundingBox) const;

        /**
         * Gets the current location of the SceneNode
         * @return a vector pair (x,y) representing the world coordinate
         */
        const Vector2d& getLocation() const;

        /**
         * Simple getter
         * @return the size of the SceneNode
         */
        const Vector2d& getSize() const;

        /**
         * Simple getter
         * @return the name of the SceneNode
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
         * @return the category of the SceneNode
         */
        virtual unsigned int getCategory() const;

        /**
         * Simple setter
         * @param location: the new location of the SceneNode
         */
        void setLocation(const Vector2d& location);

        /**
         * Simple setter
         * @param size: the size of the SceneNode (in world coordinates)
         */
        void setSize(const Vector2d& size);

        /**
         * Simple setter
         * @param width: the width of the SceneNode
         */
        void setWidth(double width);

        /**
         * Simple setter
         * @param height: the height of the SceneNode
         */
        void setHeight(double height);

        /**
         * Sets the renderer of this SceneNode
         * @param renderer
         */
        void setRenderer(const Renderer& renderer);

protected:
        /**
         * The location of the SceneNode.
         */
        Vector2d mLocation;

private:

        /**
         * The name of the SceneNode
         */
        std::string mName;

        /**
         * The size of the SceneNode
         */
        Vector2d mSize;

        /**
         * Used to render the SceneNode.
         */
        std::unique_ptr<Renderer> mRenderer;
};

} // namespace turboHiker