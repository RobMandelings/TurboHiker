//
// Created by Rob Mandelings on 31/12/2020.
//

#pragma once

#include "Renderable.h"
#include "Updatable.h"
#include <memory>
#include <vector>

namespace turboHiker {

class SceneNode;
class Hiker;
class PlayerHiker;
class Command;

/**
 * Container class which holds and keeps track of (updating, rendering,...) all SceneNodes present in the world, except
 * for the world itself. These are actually the 'children' sceneNodes of the world itself, but it also implements some
 * more safety in getting references to certain SceneNodes as well as instantly getting the derived objects which
 * minimizes the usage of dynamic casting.
 */
class SceneGraph : public Updatable, public Renderable
{

public:
        void update(seconds dt) override;
        void updateRenderComponents(seconds dt);
        void render() const override;
        void cleanupDeadObjects();

        void onCommand(const Command& command, std::chrono::duration<double> dt);

        unsigned int getAmountOfSceneNodes() const;

        unsigned int getAmountOfLanes() const;

        unsigned int getAmountOfCompetingHikers() const;

        Hiker& getPlayerHiker() const;

        SceneNode& getSceneNode(unsigned int index) const;

        Hiker& getCompetingHiker(unsigned int index) const;

        SceneNode& getLane(unsigned int index) const;

        void addSceneNode(const SceneNode& sceneNode);

        void addCompetingHiker(const Hiker& competingHiker);

        void setPlayerHiker(const Hiker& playerHiker);

        void addLane(const SceneNode& lane);

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

        std::weak_ptr<Hiker> mPlayerHiker;

        /**
         * The lanes that make up this world. These can be any SceneNodes though, as the visual representation depends
         * on its implementation.
         */
        std::vector<std::weak_ptr<SceneNode>> mLanes;
};
} // namespace turboHiker