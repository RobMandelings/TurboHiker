//
// Created by Rob Mandelings on 22/12/2020.
//

#include "BoundingBox.h"
turboHiker::BoundingBox::BoundingBox(double left, double bottom, double width, double height)
    : mLeft(left), mBottom(bottom), mWidth(width), mHeight(height)
{
}

double turboHiker::BoundingBox::getLeft() const { return mLeft; }
double turboHiker::BoundingBox::getTop() const { return mBottom + mHeight; }
double turboHiker::BoundingBox::getBottom() const { return mBottom; }
double turboHiker::BoundingBox::getRight() const { return mLeft + mWidth; }
double turboHiker::BoundingBox::getWidth() const { return mWidth; }
double turboHiker::BoundingBox::getHeight() const { return mHeight; }

bool turboHiker::BoundingBox::empty() const
{
        return getBottom() == 0 && getLeft() == 0 && getWidth() == 0 && getHeight() == 0;
}