//
// Created by RobMa on 19/12/2020.
//

#pragma once

#include "Commandable.h"
#include "Removable.h"
#include "Renderable.h"
#include "Updatable.h"
#include "Vector2d.h"

#include <memory>
#include <set>
#include <vector>

namespace turboHiker {

class Renderer;
class BoundingBox;
class Command;
class Vector2d;

/**
 * Fundamental object to the game. Can be decoration
 */
class SceneNode : public Updatable, public Renderable, public Commandable, public Removable
{

public:
        SceneNode(const Vector2d& initialLocation, const Vector2d& boundingSize, std::string name);

        SceneNode();
        SceneNode(const SceneNode& other);

        void update(seconds dt) override;
        void updateRenderComponent(seconds dt) const;

        void onCommand(const Command& command, seconds dt) override;

        void render() const override;

        bool collidesWith(const SceneNode& other) const;
        bool collidesWith(const BoundingBox& boundingBox) const;

        const Vector2d& getLocation() const;
        const Vector2d& getSize() const;
        const std::string& getName() const;
        /**
         * Gets the current bounding box of the entity depending on its bounding size and relative to its current
         * location. Used for collision detection. The location is always centered in the middle of the bounding box.
         * @return
         */
        BoundingBox getBoundingBox() const;
        bool hasBoundingBox() const;

        virtual unsigned int getCategory() const;

        void setLocation(const Vector2d& newLocation);
        void setSize(const Vector2d& boundingSize);
        void setWidth(double width);
        void setHeight(double height);

        void setRenderer(const Renderer& renderer);

protected:
        /**
         * The location of the entity.
         */
        Vector2d mLocation;

private:
        std::string mName;

        Vector2d mSize;

        /**
         * Used to render the node.
         */
        std::unique_ptr<Renderer> mRenderer;
};

} // namespace turboHiker