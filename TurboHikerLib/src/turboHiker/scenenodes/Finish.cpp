//
// Created by RobMa on 4/01/2021.
//

#include "Finish.h"
#include "BoundingBox.h"
#include "GameCategory.h"

turboHiker::Finish::Finish(const BoundingBox& span)
    : SceneNode(Vector2d(span.getLeft() + span.getWidth() / 2, span.getBottom() + span.getHeight() / 2),
                Vector2d(span.getWidth(), span.getHeight()), "Finish")
{
}

unsigned int turboHiker::Finish::getCategory() const { return GameCategory::GameFinish; }