//
// Created by RobMa on 19/12/2020.
//

#include "GameObject.h"

#include <algorithm>
#include <cassert>

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

void GameObject::draw() const {}
void GameObject::update(Updatable::seconds dt) {}

const Vector2d& GameObject::getLocation() const { return mCurrentLocation; }
void GameObject::setLocation(const Vector2d& currentLocation) { mCurrentLocation = currentLocation; }
} // namespace turboHiker