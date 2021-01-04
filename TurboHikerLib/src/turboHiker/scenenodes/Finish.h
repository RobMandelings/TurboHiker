//
// Created by RobMa on 4/01/2021.
//

#ifndef TURBOHIKER_FINISH_H
#define TURBOHIKER_FINISH_H

#endif // TURBOHIKER_FINISH_H

#include "SceneNode.h"
#include <turboHiker/enums.h>

namespace turboHiker {
class Finish : public SceneNode
{

public:


private:
public:
        Finish(const Vector2d& initialLocation, const Vector2d& boundingSize,
               std::unique_ptr<SceneNodeRenderer> renderComponent, const std::string& name);
        unsigned int getCategory() const override;
};
} // namespace turboHiker