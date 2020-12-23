//
// Created by RobMa on 19/12/2020.
//

#include "Entity.h"

#include <algorithm>
#include <cassert>

#include "CollisionComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"

#include "WorldLocation.h"

#include <iostream>

namespace turboHiker {

Entity::Entity(std::unique_ptr<PhysicsComponent> physicsComponent, std::unique_ptr<InputComponent> inputComponent,
               std::unique_ptr<RenderComponent> renderComponent)
    : mParent(nullptr), mInputComponent(std::move(inputComponent)), mPhysicsComponent(std::move(physicsComponent)),
      mRenderComponent(std::move(renderComponent))
{
        // De moment dat je make_unique doet wordt er een kopie gemaakt van dat object en daarna is er een pointer naar
        // dat object. Dit zorgt ervoor dat je geen meerdere pointers can hebben die allebei naar dat object wijzen,
        // aangezien je de pointer niet kan kopieren en niet maken (want make unique kopieert)
}

void Entity::attachChild(Entity::SceneNodePtr child)
{
        child->mParent = this;
        mChildren.push_back(std::move(child));
}
Entity::SceneNodePtr Entity::detachChild(const Entity& gameObject)
{
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&gameObject](SceneNodePtr& p) { return p.get() == &gameObject; });
        assert(found != mChildren.end());

        SceneNodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool Entity::hasChildren() { return !mChildren.empty(); }

void Entity::update(Updatable::seconds dt)
{

        updateCurrent(dt);
        // Update the render component so it can alter its RenderState / Representation / ...
        // TODO improve to not use the absolute location directly
        // TODO use getWorldLocation() function to get the absolute location
        mRenderComponent->update(dt, mPhysicsComponent->getLocation());

        updateChildren(dt);
}

void Entity::updateCurrent(Updatable::seconds dt) { mPhysicsComponent->update(dt); }
void Entity::updateChildren(Updatable::seconds dt)
{
        for (const SceneNodePtr& child : mChildren) {
                child->update(dt);
        }
}

void Entity::render() const
{
        renderCurrent();
        renderChildren();
}

void Entity::renderCurrent() const { mRenderComponent->render(); }

void Entity::renderChildren() const
{
        for (const SceneNodePtr& gameObjectPtr : mChildren) {
                gameObjectPtr->render();
        }
}

const Vector2d& Entity::getLocation() const { return mPhysicsComponent->getLocation(); }
void Entity::setLocation(const Vector2d& newLocation) { mPhysicsComponent->setWorldLocation(newLocation); }
} // namespace turboHiker