//
// Created by RobMa on 21/12/2020.
//

#ifndef TURBOHIKER_SCENENODEFACTORYSFML_H
#define TURBOHIKER_SCENENODEFACTORYSFML_H

#include "SceneNodeFactory.h"
#include <RunningHiker.h>
#include <StaticHiker.h>
#include <memory>
#include <turboHiker/scenenodes/entities/PlayerHiker.h>

namespace turboHiker {
class SceneNode;
}

/**
 * Creates Entities (A type of Type that can move) with a specific VisualComponent created with SFML to give a
 * visual representation to these scenenodes
 */
namespace turboHiker {

using namespace turboHiker;

class DrawableRenderer;

/**
 * Factory to create SceneNodes, with the rendering done using SFML
 */
class SceneNodeFactorySFML : public turboHiker::SceneNodeFactory
{

public:
        /**
         * Simple constructor
         * @param drawableRenderer: the renderer which is responsible for drawing drawables onto the screen
         */
        explicit SceneNodeFactorySFML(DrawableRenderer& drawableRenderer);

        /**
         * Creates the PlayerHiker in SFML representation. See SceneNodeFactory for parameter details
         */
        PlayerHiker createPlayerHiker(double yLocation, const Vector2d& size, double slowSpeed,
                                      double fastSpeed) const override;

        /**
         * Creates the StaticHiker in SFML representation. See SceneNodeFactory for parameter details
         */
        StaticHiker createStaticHiker(double yLocation, const Vector2d& size) const override;

        /**
         * Creates the MovingHiker in SFML representation. See SceneNodeFactory for parameter details
         */
        RunningHiker createMovingHiker(double yLocation, const Vector2d& size, const Vector2d& velocity) const override;

        /**
         * Creates the Lane in SFML representation. See SceneNodeFactory for parameter details
         */
        SceneNode createLane(const turboHiker::BoundingBox& laneDimensions) const override;

        /**
         * Creates the Finish in SFML representation. See SceneNodeFactory for parameter details
         */
        Finish createFinish(const BoundingBox& finishDimensions) const override;

private:
        /**
         * the renderer which is responsible for drawing drawables onto the screen
         */
        DrawableRenderer& mDrawableRenderer;
};
} // namespace turboHiker

#endif // TURBOHIKER_SCENENODEFACTORYSFML_H