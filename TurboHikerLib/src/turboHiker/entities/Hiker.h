//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"

namespace turboHiker {
/** An SceneNode which only takes an InputComponent and RenderComponent. The MovingPhysicsComponent is created inside here
 */
class Hiker : public Entity
{

public:
        Hiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
              std::unique_ptr<RenderComponent> renderComponent, const Vector2d& initialVelocity);
        unsigned int getCategory() const override;

        int getCurrentLane() const;
        void setCurrentLane(int currentLane);

private:

        int mCurrentLane;

        bool mPlayerControlled;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKER_H
