#pragma once

#include "HikeStatus.h"
#include "Updatable.h"

#include <cassert>
#include <chrono>
#include <functional>

namespace turboHiker {

class Commandable;

/**
 * Holds a function which can be executed on a class implementing a Commandable interface to execute specific things on
 * objects like SceneNodes and the World
 */
struct Command
{

        /**
         * Simple constructor
         */
        Command();

        /**
         * The function that is to be executed on the specific class implementing the Commandable interface
         */
        std::function<void(Commandable&, Updatable::seconds dt)> action;

        /**
         * The category(s) this command should be executed on. For example: category RunningHiker & StaticHiker
         * indicates that the command should be executed on both a RunningHiker and a StaticHiker
         */
        unsigned int category;

        /**
         * In which stage of the game (e.g. before the start of the game, whilst hiking, when finished a hike,...) the
         * command should be executed.
         */
        unsigned int whenToExecute;
};

/**
 * Convenience template function to automatically get the specific derived class that implements the Commandable
 * interface to execute more specific commands concerning this class.
 * @tparam GameObject: the GameObject that should be a derivation of the Commandable interface
 * @tparam Function: the function which takes a derivation from the Commandable interface as parameter (the GameObject)
 * @param fn: same as function
 * @return the more general function so you can set it as an action in a Command object
 */
template <typename GameObject, typename Function>
std::function<void(Commandable&, Updatable::seconds dt)> derivedSceneNodeCommand(Function fn)
{
        return [=](Commandable& node, Updatable::seconds dt) {
                // Check if cast is safe
                assert(dynamic_cast<GameObject*>(&node) != nullptr);

                // Downcast node and invoke function on it
                fn(static_cast<GameObject&>(node), dt);
        };
}
} // namespace turboHiker