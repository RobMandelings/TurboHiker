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
        Entity(const turboHiker::Vector2d& initialLocation, const Vector2d& boundingSize,
               std::unique_ptr<RenderComponent> renderComponent, const turboHiker::Vector2d& mVelocity,
               const std::string& name = "Entity");

        void setVelocity(const Vector2d& newVelocity);

        void accelerate(const Vector2d& acceleration);

protected:
        void updateCurrent(seconds dt) override;
private:

        Vector2d mVelocity;

};
} // namespace turboHiker

#endif // TURBOHIKER_ENTITY_H
