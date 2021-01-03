//
// Created by RobMa on 23/12/2020.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H

#include "Entity.h"

namespace turboHiker {
/** An SceneNode which only takes an InputComponent and SceneNodeRenderer. The MovingPhysicsComponent is created inside here
 */
class Hiker : public Entity
{

public:

        // TODO implement more safety so the hiker can only move up or down
        Hiker(const Vector2d& initialLocation, const Vector2d& boundingSize,
              std::unique_ptr<SceneNodeRenderer> renderComponent, const Vector2d& initialVelocity,
              bool playerControlled, const std::string& name);
        unsigned int getCategory() const override;

        int getCurrentLane() const;
        void setCurrentLane(int currentLane);

        void onYelledAt();

        bool isPlayerControlled() const;

private:

        int mCurrentLane;

        bool mPlayerControlled;
};
} // namespace turboHiker

#endif // TURBOHIKER_HIKER_H
