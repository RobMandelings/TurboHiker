//
// Created by RobMa on 19/12/2020.
//

#include "SceneNode.h"

#include <algorithm>
#include <cassert>

#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "InputComponent.h"

#include "WorldPosition.h"

namespace turboHiker {

SceneNode::SceneNode(std::unique_ptr<PhysicsComponent> physicsComponent, std::unique_ptr<RenderComponent> renderComponent, std::unique_ptr<InputComponent> inputComponent)
    : mParent(nullptr), mInputComponent(std::move(inputComponent)), mPhysicsComponent(std::move(physicsComponent)), mRenderComponent(std::move(renderComponent))
{
        // De moment dat je make_unique doet wordt er een kopie gemaakt van dat object en daarna is er een pointer naar
        // dat object. Dit zorgt ervoor dat je geen meerdere pointers can hebben die allebei naar dat object wijzen,
        // aangezien je de pointer niet kan kopieren en niet maken (want make unique kopieert)
}

void SceneNode::attachChild(SceneNode::SceneNodePtr child)
{
        child->mParent = this;
        mChildren.push_back(std::move(child));
}
SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode& gameObject)
{
        auto found = std::find_if(mChildren.begin(), mChildren.end(),
                                  [&gameObject](SceneNodePtr& p) { return p.get() == &gameObject; });
        assert(found != mChildren.end());

        SceneNodePtr result = std::move(*found);
        result->mParent = nullptr;
        mChildren.erase(found);

        return result;
}
bool SceneNode::hasChildren() { return !mChildren.empty(); }

void SceneNode::update(Updatable::seconds dt)
{
        updateCurrent(dt);
        updateChildren(dt);
}

void SceneNode::updateCurrent(Updatable::seconds dt)
{
        // Do nothing by default, can be implemented if wanted
}
void SceneNode::updateChildren(Updatable::seconds dt)
{
        for (const SceneNodePtr& child : mChildren) {
                child->update(dt);
        }
}

void SceneNode::draw() const
{
        // This draw method is executed as if the location was absolute (probably top of the Hierarchy, called by
        // world.draw()). If this is not the case, you should use draw(currentAbsoluteLocation) instead
        draw(getLocation());
}

void SceneNode::draw(const Vector2d& currentAbsoluteLocation) const
{
        drawCurrent(currentAbsoluteLocation);
        drawChildren(currentAbsoluteLocation);
}
void SceneNode::drawCurrent(const Vector2d& currentAbsoluteLocation) const { mRenderComponent->draw(); }

void SceneNode::drawChildren(Vector2d currentAbsoluteLocation) const
{
        for (const SceneNodePtr& gameObjectPtr : mChildren) {
                gameObjectPtr->draw(currentAbsoluteLocation);
        }
}

const Vector2d& SceneNode::getLocation() const { return mPhysicsComponent->getWorldPosition().getVectorPositionRef(); }
void SceneNode::setLocation(const Vector2d& newLocation) { mPhysicsComponent->setWorldLocation(newLocation); }
} // namespace turboHiker