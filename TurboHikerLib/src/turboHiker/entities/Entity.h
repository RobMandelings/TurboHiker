//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include "Removable.h"
#include "Renderable.h"
#include "Updatable.h"

#include <memory>
#include <vector>

#include "Vector2d.h"

namespace turboHiker {

class PhysicsComponent;
class RenderComponent;
class InputComponent;
class BoundingBox;

/**
 * Fundamental object to the game. Can be decoration
 */
class Entity : public Updatable, public Renderable, public Removable
{

public:
        typedef std::unique_ptr<Entity> SceneNodePtr;

        Entity(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> mBoundingBox,
               std::unique_ptr<RenderComponent> renderComponent);

        Entity();

        void update(seconds dt) final;

        void render() const final;

        void attachChild(SceneNodePtr child);
        SceneNodePtr detachChild(const Entity& gameObject);
        bool hasChildren();

        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& newLocation);

        void handleCollision(const Entity& entity);

        bool hasBoundingBox() const;

        bool collidesWith(const Entity& entity) const;

        // TODO make this type-safe
        virtual unsigned int getCategory() const;

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
        virtual void handleCollisionInternal(const Entity& entity);

protected:
        /**
         * The location of the entity. If its a child of another entity it is relative to the location of that entity.
         * If it's the root, it is already the absolute location
         */
        Vector2d mLocation;

        std::unique_ptr<BoundingBox> mBoundingBox;

private:
        Entity* mParent;
        std::vector<SceneNodePtr> mChildren;

        /**
         * Used to render the node
         */
        std::unique_ptr<RenderComponent> mRenderComponent;
};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITY_H
