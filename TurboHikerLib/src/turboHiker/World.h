//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "Drawable.h"
#include "Entity.h"
#include "Updatable.h"
#include "EntityFactory.h"

#include "InputComponent.h"
#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include "CollisionComponent.h"

#include <memory>

namespace turboHiker {
class World : private Updatable, private Drawable
{

public:
        World(std::unique_ptr<EntityFactory> entityFactory);

        void update(seconds dt) override;
        void draw() const override;

private:

        void buildWorld();

        /**
         * This is Main Game Object of the world, it contains all sub game objects (can be entities, decorations,...)
         */
        std::vector<std::unique_ptr<Entity>> mMainEntities;

        std::unique_ptr<EntityFactory> mEntityFactory;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H