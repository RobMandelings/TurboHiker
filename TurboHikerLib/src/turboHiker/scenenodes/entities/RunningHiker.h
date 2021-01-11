//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "Hiker.h"

namespace turboHiker {
class RunningHiker : public Hiker
{

public:
        RunningHiker(const Vector2d& location, const Vector2d& boundingSize, const Vector2d& velocity,
                     const std::string& name);
        unsigned int getCategory() const override;
        void onYelledAt() override;
};
} // namespace turboHiker