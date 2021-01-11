#pragma once

#include "Updatable.h"
#include "HikeStatus.h"

#include <cassert>
#include <chrono>
#include <functional>

namespace turboHiker {

class Commandable;

struct Command
{
        Command();

        std::function<void(Commandable&, Updatable::seconds dt)> action;
        unsigned int category;
        HikeStatus whenToExecute;
};

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