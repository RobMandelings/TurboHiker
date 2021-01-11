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
 * Creates Entities (A type of SceneNode that can move) with a specific VisualComponent created with SFML to give a
 * visual representation to these scenenodes
 */
namespace turboHiker {

using namespace turboHiker;

class DrawableRenderer;

class SceneNodeFactorySFML : public turboHiker::SceneNodeFactory
{

public:
        SceneNodeFactorySFML(DrawableRenderer& mWindowDrawer);

        PlayerHiker createPlayerHiker(double yLocation, const Vector2d& size, double slowSpeed,
                                double fastSpeed) const override;

        StaticHiker createStaticHiker(double yLocation, const Vector2d& size) const override;
        RunningHiker createMovingHiker(double yLocation, const Vector2d& size, const Vector2d& velocity) const override;

        SceneNode createLane(const turboHiker::BoundingBox& laneDimensions) const override;
        Finish createFinish(const BoundingBox& finishDimensions) const override;

private:
        DrawableRenderer& mWindowRenderer;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_SCENENODEFACTORYSFML_H