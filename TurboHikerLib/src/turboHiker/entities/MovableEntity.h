//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_MOVABLEENTITY_H
#define TURBOHIKER_MOVABLEENTITY_H

#include "SceneNode.h"

namespace turboHiker {
class MovableEntity : public SceneNode
{

public:
        MovableEntity(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> mBoundingBox,
                      std::unique_ptr<RenderComponent> renderComponent, const Vector2d& mVelocity);

        void setVelocity(const Vector2d& newVelocity);

        void accelerate(const Vector2d& acceleration);

private:
        void updateCurrent(seconds dt) override;

private:

        Vector2d mVelocity;

};
} // namespace turboHiker

#endif // TURBOHIKER_MOVABLEENTITY_H
