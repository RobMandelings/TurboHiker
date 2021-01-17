//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#include "Observable.h"
#include "Renderable.h"
#include "SceneGraph.h"
#include "SceneNode.h"
#include "SceneNodeFactory.h"

#include "BoundingBox.h"
#include "Renderer.h"
#include "HikeStatus.h"

#include "CommandQueue.h"
#include "HighScoreContainer.h"

#include <memory>

namespace turboHiker {

class Score;

/**
 * Contains the main game logic. Does all the updating, keeps track of a SceneGraphs, delegates render requests, keeps
 * track of the CommandQueue and delegates the commands using the SceneGraph,...
 */
class World : public Updatable, public Renderable, public Commandable, private Observable
{

public:
        /**
         * Simple constructor
         * @param worldBorders: the borders that cover up the entire world
         */
        explicit World(const BoundingBox& worldBorders);

        /**
         * Handle collisions between all SceneNodes present in the world
         */
        void handleCollisions();

        /**
         * Checks if two SceneNodes in a SceneNodePair matches the given category
         * @param sceneNodePair: the pair of SceneNodes to check for
         * @param type1: the first category to check
         * @param type2: the second category to check
         * @return true if the pair matches these categories, false if not
         */
        static bool matchesCategories(SceneGraph::SceneNodePair& sceneNodePair, GameCategory type1, GameCategory type2);

        /**
         * Sets the entity factory for this world. As the Entity Factory uses the Abstract Factory Pattern, this must be
         * set accordingly by its specific implementation
         * @param entityFactory: the entity factory to add
         */
        void setEntityFactory(std::unique_ptr<SceneNodeFactory> entityFactory);

        /**
         * Simple getter
         * @return the command queue holding the current commands
         */
        CommandQueue& getCommandQueue();

        /**
         * Put a hiker on a specific lane
         * @param hiker: the hiker to put on the lane
         * @param laneIndex: the lane index to put the hiker on
         */
        void putHikerOnLane(Hiker& hiker, int laneIndex, bool instantly);

        /**
         * Executed whenever a Hiker yelled. It checks for neighbouring hikers and if it finds one to yell at, that
         * hiker will know
         * @param hiker: the hiker that has yelled
         * @param yellDistance: how far the yell reaches
         */
        void hikerYelled(Hiker& hiker, double yellDistance);

        /**
         * Builds the world with given amount of lanes
         * @param nrLanes: the amount of lanes to build the world with
         */
        void buildWorld(int nrLanes);

        /**
         * Generate competing hikers during the gameplay on the fly. Creates a dynamic effect so no two games look the
         * same and is quite random
         * @param dt: the timestap used for time-based actions
         */
        void generateCompetingHikers(seconds dt);

        /**
         * Mark all competing hikers for removal if they fall out of sight for example (efficiency purposes)
         */
        void removeCompetingHikers();

        /**
         * Tracks the player using the View System
         */
        void trackPlayer() const;

        /**
         * Simple getter
         * @return the boundingBox containing the borders of the world
         */
        const BoundingBox& getWorldBorders() const;

        /**
         * Do one update of the world
         * @param dt: the timestep to update the world with
         */
        void update(seconds dt) override;

        /**
         * Whenever a command should be executed. Executes the command itself if applicable, otherwise delegate commands
         * to the children (SceneNodes) of the world
         * @param command: the command executed
         * @param dt: time step used for time-based commands
         */
        void onCommand(const Command& command, Updatable::seconds dt) override;

        /**
         * Render the world
         */
        void render() const override;

        /**
         * Simple getter
         * @return the amount of lanes
         */
        unsigned int getAmountOfLanes() const;

        /**
         * Simple getter
         * @return the amount of competing hikers currently present in the world
         */
        unsigned int getAmountOfCompetingHikers() const;

        /**
         * Simple getter
         * @return reference to the PlayerHiker instance
         */
        PlayerHiker& getPlayerHiker() const;

        /**
         * Simple getter
         * @return the current hike status
         */
        HikeStatus getHikeStatus() const;

        /**
         * Starts the hike, sets all initial values to actually begin hiking
         */
        void startHiking();

        /**
         * Resets the hike so that you can start over again. Also saves previous score if its a HighScore
         */
        void resetHike(bool saveHighScore);

        /**
         * Called whenever a finish is reached
         */
        void endHike();

        /**
         * Simple getter
         * @return reference to the current Score
         */
        const Score& getScore() const;

        /**
         * Simple getter
         * @return reference to the container which holds all current HighScores
         */
        const HighScoreContainer& getHighScores() const;

private:
        /**
         * Contains all the SceneNodes that are present in the world, except for the world itself
         */
        SceneGraph mSceneGraph;

        /**
         * Contains all current commands waiting to be executed
         */
        CommandQueue mCommandQueue;

        /**
         * SceneNode factory to provide the world with a way to generate more entities
         */
        std::unique_ptr<SceneNodeFactory> mSceneNodeFactory;

        /**
         * The borders of the world
         */
        BoundingBox mWorldBorders;

        /**
         * Current score
         */
        std::shared_ptr<Score> mScore;

        /**
         * Container containing all current highScores
         */
        HighScoreContainer mHighscores;

        /**
         * The lane at which a previous enemy spawned. Used to not generate multiple the same lane directly one after
         * another
         */
        int mPreviousLaneEnemySpawned;

        /**
         * The current status of the Hike, used to check if enemies need to be spawned, certain collision detections
         * need to be done,...
         */
        HikeStatus mHikeStatus;
};
} // namespace turboHiker

#endif // TURBOHIKER_WORLD_H