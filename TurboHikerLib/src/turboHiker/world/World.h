//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "EntityFactory.h"
#include "Renderable.h"
#include "SceneGraph.h"
#include "SceneNode.h"

#include "BoundingBox.h"
#include "SceneNodeRenderer.h"

#include "CommandQueue.h"

#include <memory>

namespace turboHiker {

class World : public Updatable, public Renderable, public Commandable
{

public:
        World(int nrLanes, double laneWidth, double laneHeight);

        void handleCollisions();

        static bool matchesCategories(SceneGraph::SceneNodePair& colliders, GameCategory type1, GameCategory type2);

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
        void update(seconds dt) override;
        void renderWorld();
        void onCommand(const Command& command, Updatable::seconds dt) override;
        void render() const override;

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