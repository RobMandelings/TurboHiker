//
// Created by Rob Mandelings on 11/01/2021.
//

#pragma once

#include "Hiker.h"

namespace turboHiker {
class StaticHiker : public Hiker
{

public:
        StaticHiker(const turboHiker::Vector2d& location, const turboHiker::Vector2d& boundingSize,
                    const std::string& name);

public:
        void onYelledAt() override;
        unsigned int getCategory() const override;
};
}
