//
// Created by RobMa on 19/12/2020.
//

#include "GameObject.h"

#include <algorithm>
#include <cassert>

#include "VisualComponent.h"

namespace turboHiker {

void GameObject::attachChild(GameObject::GameObjectPtr child)
{
        child->mParent = this;
        mChildren.push_back(std::move(child));
}
GameObject::GameObjectPtr GameObject::detachChild(const GameObject& gameObject)
{
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&gameObject](GameObjectPtr& p) { return p.get() == &gameObject; });
        assert(found != mChildren.end());

        GameObjectPtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool GameObject::hasChildren() { return !mChildren.empty(); }

void GameObject::update(Updatable::seconds dt)
{
        updateCurrent(dt);
        updateChildren(dt);
}

void GameObject::updateCurrent(Updatable::seconds dt)
{
        // Do nothing by default, can be implemented if wanted
}
void GameObject::updateChildren(Updatable::seconds dt)
{
        for (const GameObjectPtr& child : mChildren) {
                child->update(dt);
        }
}

void GameObject::draw() const
{
        // This draw method is executed as if the location is absolute. If this is not the case, you should use
        // draw(currentAbsoluteLocation) instead
        draw(getLocation());
}

void GameObject::draw(const Vector2d& currentAbsoluteLocation) const
{
        drawCurrent(currentAbsoluteLocation);
        drawChildren(currentAbsoluteLocation);
}
void GameObject::drawCurrent(const Vector2d& currentAbsoluteLocation) const
{
        visualComponent->draw(currentAbsoluteLocation);
}

void GameObject::drawChildren(Vector2d currentAbsoluteLocation) const
{
        for (const GameObjectPtr& gameObjectPtr : mChildren) {
                gameObjectPtr->draw(currentAbsoluteLocation);
        }
}

const Vector2d& GameObject::getLocation() const { return mCurrentLocation; }
void GameObject::setLocation(const Vector2d& currentLocation) { mCurrentLocation = currentLocation; }
} // namespace turboHiker