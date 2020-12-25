//
// Created by Rob Mandelings on 22/12/2020.
//

#pragma once

namespace turboHiker {
class BoundingBox
{

public:
        BoundingBox(double left, double top, double width, double height);

        double getLeft() const;
        double getTop() const;
        double getBottom() const;
        double getRight() const;
        double getWidth() const;
        double getHeight() const;

        bool empty() const;

private:
        double mLeft;
        double mTop;
        double mWidth;
        double mHeight;
};
} // namespace turboHiker