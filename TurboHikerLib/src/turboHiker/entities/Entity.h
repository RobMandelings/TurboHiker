//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include "SceneNode.h"

namespace turboHiker {

/**
 * An entity is a scene node which can move over time as it has velocity
 */
class Entity : public SceneNode
{

public:
        Entity(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> mBoundingBox,
                      std::unique_ptr<RenderComponent> renderComponent, const Vector2d& mVelocity);

        void setVelocity(const Vector2d& newVelocity);

        void accelerate(const Vector2d& acceleration);

private:
        void updateCurrent(seconds dt) override;

private:

        Vector2d mVelocity;

};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITY_H
