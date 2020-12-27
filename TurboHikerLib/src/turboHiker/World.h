//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "EntityFactory.h"
#include "Renderable.h"
#include "SceneNode.h"
#include "Updatable.h"

#include "BoundingBox.h"
#include "RenderComponent.h"

#include "CommandQueue.h"

#include <memory>

namespace turboHiker {

class World : private Updatable, private Renderable
{

public:
        World(const BoundingBox& worldBorders);

        void update(seconds dt) override;
        void render() const override;
        void handleCollisions();

        static bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);

        void setEntityFactory(std::unique_ptr<EntityFactory> entityFactory);

        CommandQueue& getCommandQueue();

        void buildWorld();

        const BoundingBox& getWorldBorders() const;

private:

        /**
         * This is Main Game Object of the world, it contains all sub game objects (can be entities, decorations,...)
         */
        SceneNode mSceneGraph;

        CommandQueue mCommandQueue;

        std::unique_ptr<EntityFactory> mEntityFactory;

        const turboHiker::BoundingBox mWorldBorders;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H