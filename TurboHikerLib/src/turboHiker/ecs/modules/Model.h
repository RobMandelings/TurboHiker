//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

namespace turboHiker {

class Vector2d;

/**
 * This will be used by a concrete implementation of the game. It can be whatever visual library you'd like to
 * use (SFML, OpenGL, Qt,...), just set this component to a concrete implementation of the visual representation
 * of an object It must be uniquely coupled to the SceneNode (no shared instances across GameObjects), thats
 * the reason for the unique ptr
 */
class Model
{

public:

        virtual void draw(const Vector2d& worldLocation) const = 0;

};
} // namespace turboHiker
