//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_GAMEOBJECT_H
#define TURBOHIKER_GAMEOBJECT_H

#include "Updatable.h"
#include "Drawable.h"
#include "Removable.h"

namespace turboHiker {
class GameObject : public Updatable, public Drawable, public Removable
{

        void update(seconds dt) override;

        void draw() const override;
};
} // namespace turboHiker

#endif // TURBOHIKER_GAMEOBJECT_H
