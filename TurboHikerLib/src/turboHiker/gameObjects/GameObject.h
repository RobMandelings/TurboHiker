//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_GAMEOBJECT_H
#define TURBOHIKER_GAMEOBJECT_H

#include "Updatable.h"
#include "Drawable.h"

namespace turboHiker {
class GameObject : private Updatable, private Drawable
{

        void update(seconds dt) override;

        void draw() const override;
};
} // namespace turboHiker

#endif // TURBOHIKER_GAMEOBJECT_H
