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
 * more safety regarding the 'getting derived references for SceneNodes'. It delegates it update request to the
 * children, and removes them if necessary.
 */
class SceneGraph : public Updatable, public Renderable
{

public:
        void update(seconds dt) override;
        void updateRenderComponents(seconds dt);
        void render() const override;

        Hiker& getPlayerHiker() const;

        void onCommand(const Command& command, std::chrono::duration<double> dt);

        const std::vector<std::unique_ptr<SceneNode>>& getSceneNodes() const;

        const std::vector<std::unique_ptr<Hiker>>& getCompetingHikers() const;

        const std::vector<std::unique_ptr<SceneNode>>& getLanes() const;

        void addSceneNode(const SceneNode& sceneNode);

        void addCompetingHiker(const Hiker& competingHiker);

        void setPlayerHiker(const Hiker& playerHiker);

        void addLane(const SceneNode& lane);

private:

        // TODO improve performance so the list is only updated whenever something is updated in one of the other lists
        /**
         * Private method as it should only be used internally as a helper function, and this list may not be kept alive
         * outside to avoid any invalidated references to objects that are removed / destroyed.
         * @return
         */
        std::vector<std::reference_wrapper<SceneNode>> getChildren() const;
        /**
         * Basic SceneNodes that make up the world. They can be everything derived from SceneNode as well. SceneNodes
         * who update, render and do everything on their own can be put in here, as no special references /
         * communication is specifically required between these.
         */
        std::vector<std::unique_ptr<SceneNode>> mSceneNodes;

        /**
         * Competing Hikers that are currently present in the world. They stand on one of the tracks present in this
         * world as well. These renderers are applicable for collision detection as well.
         */
        std::vector<std::unique_ptr<Hiker>> mCompetingHikers;

        std::unique_ptr<Hiker> mPlayerHiker;

        /**
         * The lanes that make up this world. These can be any SceneNodes though, as the visual representation depends
         * on its implementation.
         */
        std::vector<std::unique_ptr<SceneNode>> mLanes;
};
} // namespace turboHiker