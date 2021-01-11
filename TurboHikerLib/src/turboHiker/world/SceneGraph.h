//
// Created by Rob Mandelings on 31/12/2020.
//

#pragma once

#include "Renderable.h"
#include "Updatable.h"
#include "GameCategory.h"
#include <memory>
#include <set>
#include <vector>

namespace turboHiker {

class SceneNode;
class StaticHiker;
class RunningHiker;
class Hiker;
class PlayerHiker;
class Command;
class BoundingBox;
class Finish;

/**
 * Container class which holds and keeps track of (updating, rendering,...) all SceneNodes present in the world, except
 * for the world itself. These are actually the 'children' sceneNodes of the world itself, but it also implements some
 * more safety in getting references to certain SceneNodes as well as instantly getting the derived objects which
 * minimizes the usage of dynamic casting.
 */
class SceneGraph : public Updatable, public Renderable
{

public:

        typedef std::pair<std::shared_ptr<SceneNode>, std::shared_ptr<SceneNode>> SceneNodePair;

        void clear();
        void update(seconds dt) override;
        void updateRenderComponents(seconds dt);
        void render() const override;
        void cleanupDeadObjects();

        std::set<SceneNodePair> findCollisionPairs() const;

        bool spaceOccupiedBy(const BoundingBox& boundingBox, const GameCategory& category);

        void onCommand(const Command& command, std::chrono::duration<double> dt);

        unsigned int getAmountOfSceneNodes() const;

        unsigned int getAmountOfLanes() const;

        unsigned int getAmountOfCompetingHikers() const;

        PlayerHiker& getPlayerHiker() const;

        SceneNode& getSceneNode(unsigned int index) const;

        Hiker& getCompetingHiker(unsigned int index) const;

        SceneNode& getLane(unsigned int index) const;

        Finish& getFinish() const;

        void addSceneNode(const SceneNode& sceneNode);

        void addStaticHiker(const StaticHiker& staticHiker);
        void addRunningHiker(const RunningHiker& runningHiker);

        void setPlayerHiker(const PlayerHiker& playerHiker);

        void addLane(const SceneNode& lane);

        void addFinish(const Finish& finish);

private:
        /**
         * Basic SceneNodes that make up the world. They can be everything derived from SceneNode as well. SceneNodes
         * who update, render and do everything on their own can be put in here, as no special references /
         * communication is specifically required between these.
         */
        std::vector<std::shared_ptr<SceneNode>> mSceneNodes;

        /**
         * Competing Hikers that are currently present in the world. They stand on one of the tracks present in this
         * world as well. These renderers are applicable for collision detection as well.
         */
        std::vector<std::weak_ptr<Hiker>> mCompetingHikers;

        std::weak_ptr<PlayerHiker> mPlayerHiker;

        /**
         * The lanes that make up this world. These can be any SceneNodes though, as the visual representation depends
         * on its implementation.
         */
        std::vector<std::weak_ptr<SceneNode>> mLanes;

        std::weak_ptr<Finish> mFinish;
};
} // namespace turboHiker