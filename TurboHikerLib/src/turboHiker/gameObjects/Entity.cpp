//
// Created by RobMa on 19/12/2020.
//

#include "Entity.h"

#include <algorithm>
#include <cassert>

#include "InputComponent.h"
#include "RenderComponent.h"
#include "ecs/components/physics/PhysicsComponent.h"

#include "WorldLocation.h"

namespace turboHiker {

Entity::Entity(std::unique_ptr<PhysicsComponent> physicsComponent, std::unique_ptr<RenderComponent> renderComponent, std::unique_ptr<InputComponent> inputComponent)
    : mParent(nullptr), mInputComponent(std::move(inputComponent)), mPhysicsComponent(std::move(physicsComponent)), mRenderComponent(std::move(renderComponent))
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
        updateChildren(dt);
}

void Entity::updateCurrent(Updatable::seconds dt)
{
        // Do nothing by default, can be implemented if wanted
}
void Entity::updateChildren(Updatable::seconds dt)
{
        for (const SceneNodePtr& child : mChildren) {
                child->update(dt);
        }
}

void Entity::draw() const
{
        // This draw method is executed as if the location was absolute (probably top of the Hierarchy, called by
        // world.draw()). If this is not the case, you should use draw(currentAbsoluteLocation) instead
        draw(getLocation());
}

void Entity::draw(const Vector2d& currentAbsoluteLocation) const
{
        drawCurrent(currentAbsoluteLocation);
        drawChildren(currentAbsoluteLocation);
}
void Entity::drawCurrent(const Vector2d& currentAbsoluteLocation) const { mRenderComponent->draw(mPhysicsComponent->getWorldLocation()); }

void Entity::drawChildren(Vector2d currentAbsoluteLocation) const
{
        for (const SceneNodePtr& gameObjectPtr : mChildren) {
                gameObjectPtr->draw(currentAbsoluteLocation);
        }
}

const Vector2d& Entity::getLocation() const { return mPhysicsComponent->getWorldLocation().getVectorPositionRef(); }
void Entity::setLocation(const Vector2d& newLocation) { mPhysicsComponent->setWorldLocation(newLocation); }
} // namespace turboHiker