//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_SCENENODE_H
#define TURBOHIKER_SCENENODE_H

#include "Removable.h"
#include "Renderable.h"
#include "Updatable.h"
#include "Commandable.h"
#include "Vector2d.h"

#include <memory>
#include <set>
#include <vector>

namespace turboHiker {

class SceneNodeRenderer;
class BoundingBox;
class Command;
class Vector2d;

/**
 * Fundamental object to the game. Can be decoration
 */
class SceneNode : public Updatable, public Renderable, public Commandable, public Removable
{

public:

        // TODO maybe use std::optional instead, although its experimental?
        SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize,
                  std::unique_ptr<SceneNodeRenderer> renderComponent, std::string name);

        SceneNode();
        SceneNode(const SceneNode& other);

        virtual void update(seconds dt) override;
        void updateRenderComponent(seconds dt) const;

        void render() const override;

        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& newLocation);

        bool collidesWith(const SceneNode& other) const;
        bool collidesWith(const BoundingBox& boundingBox) const;

        virtual unsigned int getCategory() const;

        void onCommand(const Command& command, seconds dt) override;

        const Vector2d& getSize() const;

private:

        void setBoundingSize(const Vector2d& boundingSize);
        void setBoundingWidth(double width);
        void setBoundingHeight(double height);

public:
        const std::string& getName() const;

        /**
         * Gets the current bounding box of the entity depending on its bounding size and relative to its current
         * location. Used for collision detection. The location is always centered in the middle of the bounding box.
         * @return
         */
        BoundingBox getBoundingBox() const;

        bool hasBoundingBox() const;

protected:
        /**
         * The location of the entity.
         */
        Vector2d mLocation;

private:

        std::string mName;

        Vector2d mBoundingSize;

        /**
         * Used to render the node
         */
        std::unique_ptr<SceneNodeRenderer> mRenderComponent;
};

} // namespace turboHiker

#endif // TURBOHIKER_SCENENODE_H