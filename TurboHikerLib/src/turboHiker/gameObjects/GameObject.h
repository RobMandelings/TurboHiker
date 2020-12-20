//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_GAMEOBJECT_H
#define TURBOHIKER_GAMEOBJECT_H

#include "Updatable.h"
#include "Drawable.h"
#include "Removable.h"

#include <memory>
#include <vector>

#include "Vector2d.h"

namespace turboHiker {

class GameObject : public Updatable, public Drawable, public Removable
{

public:

        typedef std::unique_ptr<GameObject> GameObjectPtr;

        void update(seconds dt) override;

        void draw() const override;

        void attachChild(GameObjectPtr child);
        GameObjectPtr detachChild(const GameObject& gameObject);
        bool hasChildren();
        const std::vector<GameObjectPtr>& getMChildren() const;
        void setMChildren(const std::vector<GameObjectPtr>& mChildren);
        const Vector2d& getCurrentLocation() const;
        void setCurrentLocation(const Vector2d& mCurrentLocation);

private:

        virtual void updateCurrent(seconds dt) = 0;
        void updateChildren(seconds dt);

        // TODO replace currentLocation with currentTransform for more flexibility
        void draw(const Vector2d& currentLocation) const;
        void drawCurrent(const Vector2d& currentLocation);
        void drawChildren(Vector2d currentLocation);

private:

        std::vector<GameObjectPtr> mChildren;

        Vector2d mCurrentLocation;
};
} // namespace turboHiker

#endif // TURBOHIKER_GAMEOBJECT_H
