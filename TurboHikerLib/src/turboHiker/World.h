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

class World : public SceneNode
{

public:
        World(int nrLanes, double laneWidth, double laneHeight);

        void handleCollisions();

        static bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);

        void setEntityFactory(std::unique_ptr<EntityFactory> entityFactory);

        CommandQueue& getCommandQueue();

        void putHikerOnLane(Hiker& hiker, int laneIndex);

        int getAmountOfLanes() const;

        void buildWorld(int nrLanes);

        void trackPlayer() const;

        const BoundingBox& getWorldBorders() const;

        Hiker& getPlayerHiker() const;
        unsigned int getCategory() const override;

private:
        void updateCurrent(seconds dt) override;

private:

        Hiker* mPlayerHiker;

        std::vector<SceneNode*> mLanes;

        CommandQueue mCommandQueue;

        std::unique_ptr<EntityFactory> mEntityFactory;

        const turboHiker::BoundingBox mWorldBorders;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H