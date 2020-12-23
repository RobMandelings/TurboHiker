//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "MovableEntity.h"

namespace turboHiker {
/** An SceneNode which only takes an InputComponent and RenderComponent. The MovingPhysicsComponent is created inside here
 */
class Hiker : public MovableEntity
{

public:
        Hiker(const Vector2d& initialLocation, std::unique_ptr<BoundingBox> boundingBox,
              std::unique_ptr<RenderComponent> renderComponent, const Vector2d& initialVelocity, bool playerControlled);
        unsigned int getCategory() const override;

private:

        bool mPlayerControlled;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKER_H
