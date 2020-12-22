//
// Created by RobMa on 21/12/2020.
//

#include "EntityFactorySFML.h"

#include "turboHiker/ecs/components/MovingPhysicsComponent.h"
#include "turboHiker/ecs/modules/physics/BoundingBox.h"
#include "turboHiker/utils/maths/Vector2d.h"
#include <memory>

using namespace turboHiker;

Entity* EntityFactorySFML::createStaticHiker(const WorldPosition& worldPosition) const {
        // Implement
        std::unique_ptr<MovingPhysicsComponent> movingPhysicsComponent = std::make_unique(worldPosition, BoundingBox(0, 0, 0, 0), Vector2d(0.0, 0.0))
}
