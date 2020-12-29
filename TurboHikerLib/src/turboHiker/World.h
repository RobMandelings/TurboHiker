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
#include <turboHiker/entities/Hiker.h>

namespace turboHiker {

class World : private SceneNode
{

public:
        World(const BoundingBox& worldBorders);

        void updateWorld(Updatable::seconds dt);

        void renderWorld() const;

        void handleCollisions();

        static bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);

        void setEntityFactory(std::unique_ptr<EntityFactory> entityFactory);

        CommandQueue& getCommandQueue();

        void buildWorld();

        void trackPlayer() const;

        const BoundingBox& getWorldBorders() const;

private:
        void updateCurrent(seconds dt) override;

private:

        Hiker* mPlayerHiker;

        CommandQueue mCommandQueue;

        std::unique_ptr<EntityFactory> mEntityFactory;

        const turboHiker::BoundingBox mWorldBorders;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H