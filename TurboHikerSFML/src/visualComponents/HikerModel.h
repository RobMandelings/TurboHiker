//
// Created by RobMa on 22/12/2020.
//

#ifndef TURBOHIKER_HIKERMODEL_H
#define TURBOHIKER_HIKERMODEL_H

#include "turboHiker/ecs/modules/Model.h"

namespace turboHikerSFML {

class HikerModel : turboHiker::Model
{

        void draw(const turboHiker::Vector2d& worldLocation) const override;
};
} // namespace turboHikerSFML

#endif // TURBOHIKER_HIKERMODEL_H
