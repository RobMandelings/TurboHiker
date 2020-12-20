//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_GAMEOBJECT_H
#define TURBOHIKER_GAMEOBJECT_H

#include "Drawable.h"
#include "Removable.h"
#include "Updatable.h"

#include <memory>
#include <vector>

#include "Vector2d.h"

namespace turboHiker {

class VisualComponent;

class GameObject : public Updatable, public Drawable, public Removable
{

public:
        typedef std::unique_ptr<GameObject> GameObjectPtr;

        void update(seconds dt) override;

        void draw() const override;

        void attachChild(GameObjectPtr child);
        GameObjectPtr detachChild(const GameObject& gameObject);

        bool hasChildren();
        const Vector2d& getLocation() const;
        void setLocation(const Vector2d& currentLocation);

private:
        virtual void updateCurrent(seconds dt);
        void updateChildren(seconds dt);

        // TODO replace currentLocation with currentTransform for more flexibility
        /**
         *
         * @param currentAbsoluteLocation: the current location of the Game Object. Due to the hierarchy and relative locations,
         * the value of currentLocation can change
         */
        void draw(const Vector2d& currentAbsoluteLocation) const;
        void drawCurrent(const Vector2d& currentAbsoluteLocation) const;
        void drawChildren(Vector2d currentAbsoluteLocation) const;

private:
        GameObject* mParent;
        std::vector<GameObjectPtr> mChildren;

        Vector2d mCurrentLocation;

        // Optional components depending on the type of GameObject

        /**
         * This will be used by a concrete implementation of the game. It can be whatever visual library you'd like to
         * use (SFML, OpenGL, Qt,...), just set this component to a concrete implementation of the visual representation
         * of an object It must be uniquely coupled to the GameObject (no shared instances across GameObjects), thats
         * the reason for the unique ptr
         */
        std::unique_ptr<VisualComponent> visualComponent;
};
} // namespace turboHiker

#endif // TURBOHIKER_GAMEOBJECT_H
