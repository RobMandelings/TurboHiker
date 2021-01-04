//
// Created by RobMa on 4/01/2021.
//

#include "Finish.h"
#include "SceneNodeRenderer.h"

turboHiker::Finish::Finish(const turboHiker::Vector2d& initialLocation, const turboHiker::Vector2d& boundingSize,
                           std::unique_ptr<SceneNodeRenderer> renderComponent, const std::string& name)
    : SceneNode(initialLocation, boundingSize, std::move(renderComponent), name)
{
}

unsigned int turboHiker::Finish::getCategory() const { return GameCategory::GameFinish; }