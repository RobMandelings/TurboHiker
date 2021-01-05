//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "Renderable.h"
#include "SceneGraph.h"
#include "SceneNode.h"
#include "SceneNodeFactory.h"

#include "BoundingBox.h"
#include "SceneNodeRenderer.h"

#include "CommandQueue.h"
#include "WorldStats.h"

#include <memory>

namespace turboHiker {

class World : public Updatable, public Renderable, public Commandable
{

public:
        World(int nrLanes, double laneWidth, double laneHeight, double basePointsRate);

        void handleCollisions();

        static bool matchesCategories(SceneGraph::SceneNodePair& colliders, GameCategory type1, GameCategory type2);

        void setEntityFactory(std::unique_ptr<SceneNodeFactory> entityFactory);

        CommandQueue& getCommandQueue();

        void putHikerOnLane(Hiker& hiker, int laneIndex);

        void hikerYelled(Hiker& hiker, double yellDistance);

        void buildWorld(int nrLanes);

        void generateCompetingHikers(seconds dt);
        void removeCompetingHikers();

        void trackPlayer() const;

        const BoundingBox& getWorldBorders() const;

        void update(seconds dt) override;
        void onCommand(const Command& command, Updatable::seconds dt) override;
        void render() const override;

        unsigned int getAmountOfLanes() const;
        unsigned int getAmountOfCompetingHikers() const;
        Hiker& getPlayerHiker() const;

        HikeStatus getHikeStatus() const;

        void updatePoints();
        double getPoints() const;
        double getPointsRate() const;

        void startHiking();

        void resetHike();

        void endHike();

        WorldStats getCurrentWorldStats();

private:
        /**
         * Contains all the SceneNodes that are present in the world, except for the world itself
         */
        SceneGraph mSceneGraph;

        CommandQueue mCommandQueue;

        std::unique_ptr<SceneNodeFactory> mSceneNodeFactory;

        const turboHiker::BoundingBox mWorldBorders;

        int mPreviousLaneEnemySpawned;

        HikeStatus mHikeStatus;

        double mCurrentPoints;

        const double BASE_POINTS_RATE;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H