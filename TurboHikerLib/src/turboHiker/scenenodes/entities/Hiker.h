//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"

namespace turboHiker {
/** An SceneNode which only takes an InputComponent and Renderer. The MovingPhysicsComponent is created inside
 * here
 */
class Hiker : public Entity
{

public:

        Hiker(const Vector2d& location, const Vector2d& boundingSize, const Vector2d& velocity,
              const std::string& name);

        int getCurrentLane() const;

        void setCurrentLane(int currentLane);

        virtual void onYelledAt() = 0;

private:
        int mCurrentLane;

        bool mPlayerControlled;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKER_H
