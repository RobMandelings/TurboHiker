//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_SCENENODE_H
#define TURBOHIKER_SCENENODE_H

#include "Drawable.h"
#include "Removable.h"
#include "Updatable.h"

#include <memory>
#include <vector>

#include "Vector2d.h"
#include "VisualComponent.h"

namespace turboHiker {

class PhysicsSystem;
class RenderSystem;

/**
 * Fundamental object to the game. Can be decoration
 */
class SceneNode : public Updatable, public Drawable, public Removable
{

        // TODO add a tagging system which denotes the type of the GameObjects (probably best an enum to not confuse
        // with other) so you can check which tag the game object has (for example Entity, Hiker,...)
        // TODO After that you should assert that you can dynamically cast to the corresponding class and then perform a
        // static cast
        // TODO Also lookup: is static casting good programming design pattern or not?

public:
        typedef std::unique_ptr<SceneNode> SceneNodePtr;

        SceneNode(std::unique_ptr<PhysicsSystem> physicsSystem, std::unique_ptr<RenderSystem> renderSystem);
        void update(seconds dt) override;

        void draw() const override;

        void attachChild(SceneNodePtr child);
        SceneNodePtr detachChild(const SceneNode& gameObject);

        bool hasChildren();
        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& currentLocation);

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
        SceneNode* mParent;
        std::vector<SceneNodePtr> mChildren;

        // Optional components depending on the type of SceneNode

        /**
         * Used to render the node
         */
        std::unique_ptr<RenderSystem> mRenderSystem;

        /**
         * Contains the main physics code for this node
         */
        std::unique_ptr<PhysicsSystem> mPhysicsSystem;
};
} // namespace turboHiker

#endif // TURBOHIKER_SCENENODE_H
