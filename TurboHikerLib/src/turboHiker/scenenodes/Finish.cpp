//
// Created by RobMa on 4/01/2021.
//

#include "Finish.h"
#include "Renderer.h"

turboHiker::Finish::Finish(const Vector2d& initialLocation, const Vector2d& boundingSize, const std::string& name)
    : SceneNode(initialLocation, boundingSize, name)
{
}

unsigned int turboHiker::Finish::getCategory() const { return GameCategory::GameFinish; }