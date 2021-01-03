//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "EntityFactory.h"
#include "Renderable.h"
#include "SceneGraph.h"
#include "SceneNode.h"
#include "Updatable.h"

#include "BoundingBox.h"
#include "SceneNodeRenderer.h"

#include "CommandQueue.h"

#include <memory>
#include <turboHiker/entities/Hiker.h>

namespace turboHiker {

class World : public SceneNode
{

public:
        World(int nrLanes, double laneWidth, double laneHeight);

        void handleCollisions();

        static bool matchesCategories(SceneGraph::SceneNodePair& colliders,
            Category::Type type1, Category::Type type2);

        void setEntityFactory(std::unique_ptr<EntityFactory> entityFactory);

        CommandQueue& getCommandQueue();

        void putHikerOnLane(Hiker& hiker, int laneIndex);

        void hikerYelled(Hiker& hiker, double yellDistance);

        unsigned int getAmountOfLanes() const;

        void buildWorld(int nrLanes);

        void generateCompetingHikers(seconds dt);
        void removeCompetingHikers();

        void trackPlayer() const;

        const BoundingBox& getWorldBorders() const;

        Hiker& getPlayerHiker() const;
        unsigned int getCategory() const override;
        void update(seconds dt) override;
        void renderWorld();

private:
        /**
         * Contains all the SceneNodes that are present in the world, except for the world itself
         */
        SceneGraph mSceneGraph;

        CommandQueue mCommandQueue;

        std::unique_ptr<EntityFactory> mEntityFactory;

        const turboHiker::BoundingBox mWorldBorders;

        int mPreviousLaneEnemySpawned;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H