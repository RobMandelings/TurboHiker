//
// Created by Rob Mandelings on 22/12/2020.
//

#include "BoundingBox.h"

using namespace turboHiker;

BoundingBox::BoundingBox(double left, double bottom, double width, double height)
    : mLeft(left), mBottom(bottom), mWidth(width), mHeight(height)
{
}

double BoundingBox::getLeft() const { return mLeft; }
double BoundingBox::getTop() const { return mBottom + mHeight; }
double BoundingBox::getBottom() const { return mBottom; }
double BoundingBox::getRight() const { return mLeft + mWidth; }
double BoundingBox::getWidth() const { return mWidth; }
double BoundingBox::getHeight() const { return mHeight; }

bool BoundingBox::empty() const { return getBottom() == 0 && getLeft() == 0 && getWidth() == 0 && getHeight() == 0; }

std::ostream& operator<<(std::ostream& os, const BoundingBox& boundingBox)
{
        return os << "(" << boundingBox.getLeft() << ", " << boundingBox.getBottom() << ", " << boundingBox.getWidth()
                  << ", " << boundingBox.getHeight() << ")";
}

const BoundingBox& BoundingBox::getEmptyBB()
{
        static const BoundingBox emptyBB(0, 0, 0, 0);
        return emptyBB;
}