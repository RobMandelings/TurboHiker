//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "EntityFactory.h"
#include "Renderable.h"
#include "SceneNode.h"
#include "Updatable.h"

#include "InputComponent.h"
#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include "CollisionComponent.h"

#include <memory>

namespace turboHiker {
class World : private Updatable, private Renderable
{

public:
        World();

        void update(seconds dt) override;
        void render() const override;

        void setEntityFactory(std::unique_ptr<EntityFactory> entityFactory);

        void buildWorld();

private:

        /**
         * This is Main Game Object of the world, it contains all sub game objects (can be entities, decorations,...)
         */
        SceneNode mSceneGraph;

        std::unique_ptr<EntityFactory> mEntityFactory;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H