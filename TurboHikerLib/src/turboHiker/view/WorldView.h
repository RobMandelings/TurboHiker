//
// Created by Rob Mandelings on 25/12/2020.
//

#pragma once

#include "Vector2d.h"

namespace turboHiker {
class WorldView
{

public:
        WorldView(double initialWorldXSize, double initialWorldYSize, const turboHiker::Vector2d& initialWorldViewCenter);
        double getWorldViewWidth() const;
        void setWidth(double worldXSize);
        double getWorldViewHeight() const;
        void setHeight(double worldYSize);
        const turboHiker::Vector2d& getWorldViewCenter() const;
        void setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter);

private:

        double mWorldXSize;
        double mWorldYSize;

        turboHiker::Vector2d mWorldViewCenter;

};
} // namespace turboHikerSFML
