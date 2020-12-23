#pragma once

#include "Category.h"

#include "Updatable.h"
#include <cassert>
#include <chrono>
#include <functional>

namespace turboHiker {

class Entity;

struct Command
{
        Command();

        std::function<void(Entity&, Updatable::seconds dt)> action;
        unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(Entity&, Updatable::seconds dt)> derivedAction(Function fn)
{
        return [=](Entity& node, Updatable::seconds dt) {
                // Check if cast is safe
                assert(dynamic_cast<GameObject*>(&node) != nullptr);

                // Downcast node and invoke function on it
                fn(static_cast<GameObject&>(node), dt);
        };
}
} // namespace turboHiker