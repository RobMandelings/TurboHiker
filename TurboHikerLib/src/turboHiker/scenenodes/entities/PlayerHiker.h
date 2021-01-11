//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_PLAYERHIKER_H
#define TURBOHIKER_PLAYERHIKER_H

#include "Hiker.h"

namespace turboHiker {
class PlayerHiker : public Hiker
{

public:
        PlayerHiker(const Vector2d& initialLocation, const Vector2d& boundingSize, const Vector2d& initialVelocity,
                    const std::string& name, double slowSpeed, double fastSpeed);

        bool goingFast() const;

        double getFastSpeed() const;
        double getSlowSpeed() const;

        void goFast();
        void goSlow();
        unsigned int getCategory() const override;

private:
        double mFastSpeed;
        double mSlowSpeed;
};
} // namespace turboHiker

#endif // TURBOHIKER_PLAYERHIKER_H