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

/**
 * Fundamental object to the game. Can be decoration
 */
class Entity : public Updatable, public Renderable, public Removable
{

        // TODO add a tagging system which denotes the type of the GameObjects (probably best an enum to not confuse
        // with other) so you can check which tag the game object has (for example Entity, Hiker,...)
        // TODO After that you should assert that you can dynamically cast to the corresponding class and then perform a
        // static cast
        // TODO Also lookup: is static casting good programming design pattern or not?

public:
        typedef std::unique_ptr<Entity> SceneNodePtr;

        Entity(std::unique_ptr<PhysicsComponent> physicsComponent, std::unique_ptr<InputComponent> inputComponent,
               std::unique_ptr<RenderComponent> renderComponent);
        void update(seconds dt) override;

        void render() const override;

        void attachChild(SceneNodePtr child);
        SceneNodePtr detachChild(const Entity& gameObject);

        bool hasChildren();
        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& newLocation);

private:
        virtual void updateCurrent(seconds dt);
        void updateChildren(seconds dt);

        // TODO replace currentLocation with currentTransform for more flexibility
        /**
         *
         * @param currentAbsoluteLocation: the current location of the Game Object. Due to the hierarchy and relative
         * locations, the value of currentLocation can change
         */
        void draw(const Vector2d& currentAbsoluteLocation) const;
        void drawCurrent(const Vector2d& currentAbsoluteLocation) const;
        void drawChildren(Vector2d currentAbsoluteLocation) const;

private:
        Entity* mParent;
        std::vector<SceneNodePtr> mChildren;

        // Components that can differ among nodes

        std::unique_ptr<InputComponent> mInputComponent;

        /**
         * Used to render the node
         */
        std::unique_ptr<RenderComponent> mRenderComponent;

        /**
         * Contains the main physics code for this node
         */
        std::unique_ptr<PhysicsComponent> mPhysicsComponent;
};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITY_H
