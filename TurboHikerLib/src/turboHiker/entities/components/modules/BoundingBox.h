//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

#include <ostream>
namespace turboHiker {
class BoundingBox
{

public:
        BoundingBox(double left, double bottom, double width, double height);

        double getLeft() const;
        double getTop() const;
        double getBottom() const;
        double getRight() const;
        double getWidth() const;
        double getHeight() const;

        bool empty() const;

private:
        double mLeft;
        double mBottom;
        double mWidth;
        double mHeight;
};

std::ostream& operator<<(std::ostream& ostream, const BoundingBox& boundingBox);

} // namespace turboHiker