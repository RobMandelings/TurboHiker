//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_SCENENODE_H
#define TURBOHIKER_SCENENODE_H

#include "Removable.h"
#include "Renderable.h"
#include "Updatable.h"

#include <memory>
#include <set>
#include <vector>

#include "Vector2d.h"

namespace turboHiker {

class RenderComponent;
class BoundingBox;
class Command;

/**
 * Fundamental object to the game. Can be decoration
 */
class SceneNode : public Updatable, public Renderable, public Removable
{

public:
        typedef std::unique_ptr<SceneNode> SceneNodePtr;
        typedef std::pair<SceneNode*, SceneNode*> Pair;

        SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize,
                  std::unique_ptr<RenderComponent> renderComponent);

        SceneNode();

        void update(seconds dt) final;

        void render() const final;

        void attachChild(SceneNodePtr child);
        SceneNodePtr detachChild(const SceneNode& child);
        bool hasChildren();

        /**
         * Called whenever a child is attached to the scene node. Can be overridden to do specific stuff when a child is
         * added
         * @param child
         */
        virtual void onChildAttached(const SceneNode& child);

        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& newLocation);

        void handleCollision(const SceneNode& entity);

        bool collidesWith(const SceneNode& other) const;

        void checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
        void checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);

        // TODO make this type-safe
        virtual unsigned int getCategory() const;

        void onCommand(const Command& command, seconds dt);

private:
        virtual void updateCurrent(seconds dt);
        void updateChildren(seconds dt);

        void renderCurrent() const;
        void renderChildren() const;

        /**
         * This function can be overriden. Called by the handleCollision() method that can be accessed from outside.
         * Some checks have been done already before this function got called;
         * @param entity: the entity it is colliding with
         */
        virtual void handleCollisionInternal(const SceneNode& entity);

        void setBoundingSize(const Vector2d& boundingSize);
        void setBoundingWidth(double width);
        void setBoundingHeight(double height);

        /**
         * Gets the current bounding box of the entity depending on its bounding size and relative to its current
         * location. Used for collision detection. The location is always centered in the middle of the bounding box.
         * @return
         */
        BoundingBox getBoundingBox() const;

        bool hasBoundingBox() const;

protected:
        /**
         * The location of the entity. If its a child of another entity it is relative to the location of that entity.
         * If it's the root, it is already the absolute location
         */
        Vector2d mLocation;

private:
        SceneNode* mParent;
        std::vector<SceneNodePtr> mChildren;

        /**
         * Used to render the node
         */
        std::unique_ptr<RenderComponent> mRenderComponent;

        Vector2d mBoundingSize;
};

bool collidesWith(const SceneNode& lhs, const SceneNode& rhs);

} // namespace turboHiker

#endif // TURBOHIKER_SCENENODE_H