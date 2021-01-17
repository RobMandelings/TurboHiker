//
// Created by Rob Mandelings on 31/12/2020.
//

#pragma once

#include "GameCategory.h"
#include "Renderable.h"
#include "Updatable.h"
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
        /**
         * Used for convenience if you would want to get a pair of two SceneNodes (for usage with collision detection,
         * for example)
         */
        typedef std::pair<std::shared_ptr<SceneNode>, std::shared_ptr<SceneNode>> SceneNodePair;

        /**
         * Removes all SceneNodes present in the SceneGraph
         */
        void clear();

        /**
         * Update alle SceneNodes in this SceneGraph
         * @param dt: the timestep
         */
        void update(seconds dt) override;

        /**
         * Update all render components in this SceneGraph
         * @param dt: the timestep
         */
        void updateRenderComponents(seconds dt);

        /**
         * Render all SceneNodes present in this SceneGraph
         */
        void render() const override;

        /**
         * Removes all SceneNodes that have been marked for removal (see documentation of Type)
         */
        void cleanupDeadObjects();

        /**
         * Find all SceneNodes that collide with eachother and put them in pairs
         * @return a set of all pairs of colliding SceneNodes
         */
        std::set<SceneNodePair> findCollisionPairs() const;

        /**
         * Checks whether or not a specific world space is occupied by a certain object with game category
         * @param boundingBox: the area you want to check for
         * @param category: the category of the game object you want to check for (e.g. 'Is this space occupied by a
         * RunningHiker?')
         * @return true if the space is occupied, false if not
         */
        bool spaceOccupiedBy(const BoundingBox& boundingBox, const GameCategory& category);

        /**
         * Delegates the command to all SceneNodes in this scenegraph so they can handle it properly
         * @param command: the command to execute
         * @param dt: the timestep to execute for time-based commands
         */
        void onCommand(const Command& command, std::chrono::duration<double> dt);

        /**
         * Simple getter
         * @return the amount of Type present in this scenegraph
         */
        unsigned int getAmountOfSceneNodes() const;

        /**
         * Simple getter
         * @return the amount of Lanes present in this scenegraph
         */
        unsigned int getAmountOfLanes() const;

        /**
         * Simple getter
         * @return the amount of Competing Hikers (either static or running) present in this Scene Graph
         */
        unsigned int getAmountOfCompetingHikers() const;

        /**
         * Simple getter
         * @return a reference to the PlayerHiker
         */
        PlayerHiker& getPlayerHiker() const;

        /**
         * Simple getter
         * @return a reference to the Type at specific index
         */
        SceneNode& getSceneNode(unsigned int index) const;

        /**
         * Simple getter
         * @return a reference to the Competing hiker at specific index
         */
        Hiker& getCompetingHiker(unsigned int index) const;

        /**
         * Simple getter
         * @return a reference to a Lane at specific index
         */
        SceneNode& getLane(unsigned int index) const;

        /**
         * Simple getter
         * @return a reference the finish Type, for checking when a player reached the finish
         */
        Finish& getFinish() const;

        /**
         * Adds a Type to the Scene Graph. Can be anything, but be aware that you can't very easily get access to
         * this Type if it would be a derived class, so the object placed in here should be able to handle itself
         * completely
         */
        void addSceneNode(const SceneNode& sceneNode);

        /**
         * Adds a Static Hiker to the SceneGraph. Can be queries easily without the need of downcasting anything
         * @param staticHiker: the staticHiker to add
         */
        void addStaticHiker(const StaticHiker& staticHiker);

        /**
         * Adds a Running Hiker to the SceneGraph. Can be queries easily without the need of downcasting anything
         * @param RunningHiker: the RunningHiker to add
         */
        void addRunningHiker(const RunningHiker& runningHiker);

        /**
         * Sets the new PlayerHiker to another Hiker
         * @param playerHiker: the new PlayerHiker
         */
        void setPlayerHiker(const PlayerHiker& playerHiker);

        /**
         * Adds a lane to the SceneGraph. Used to position hikers correctly on their respective lanes
         * @param lane: the lane Type to add
         */
        void addLane(const SceneNode& lane);

        /**
         * Sets the finish to the SceneGraph
         * @param finish: the finish to add
         */
        void setFinish(const Finish& finish);

private:
        /**
         * Basic SceneNodes that make up the world. They can be everything derived from Type as well. SceneNodes
         * who update, render and do everything on their own can be put in here, as no special references /
         * communication is specifically required between these.
         */
        std::vector<std::shared_ptr<SceneNode>> mSceneNodes;

        /**
         * Competing Hikers that are currently present in the world. They stand on one of the tracks present in this
         * world as well. These renderers are applicable for collision detection as well.
         */
        std::vector<std::weak_ptr<Hiker>> mCompetingHikers;

        /**
         * Weak pointer to the PlayerHikers
         */
        std::weak_ptr<PlayerHiker> mPlayerHiker;

        /**
         * The lanes that make up this world. These can be any SceneNodes though, as the visual representation depends
         * on its implementation.
         */
        std::vector<std::weak_ptr<SceneNode>> mLanes;

        /**
         * Weak ptr to the Finish of this ScenieGraph
         */
        std::weak_ptr<Finish> mFinish;
};
} // namespace turboHiker