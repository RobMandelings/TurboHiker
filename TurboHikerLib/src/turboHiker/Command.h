#pragma once

#include "Category.h"

#include "Updatable.h"
#include <cassert>
#include <chrono>
#include <functional>

namespace turboHiker {

class SceneNode;

struct Command
{
        Command();

        std::function<void(SceneNode&, Updatable::seconds dt)> action;
        unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, Updatable::seconds dt)> derivedAction(Function fn)
{
        return [=](SceneNode& node, Updatable::seconds dt) {
                // Check if cast is safe
                assert(dynamic_cast<GameObject*>(&node) != nullptr);

                // Downcast node and invoke function on it
                fn(static_cast<GameObject&>(node), dt);
        };
}
} // namespace turboHiker