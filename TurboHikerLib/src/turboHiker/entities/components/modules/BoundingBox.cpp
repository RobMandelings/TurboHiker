//
// Created by Rob Mandelings on 22/12/2020.
//

#include "BoundingBox.h"
turboHiker::BoundingBox::BoundingBox(double left, double top, double width, double height)
    : mLeft(left), mTop(top), mWidth(width), mHeight(height)
{
}

double turboHiker::BoundingBox::getLeft() const { return mLeft; }
double turboHiker::BoundingBox::getTop() const { return mTop; }
double turboHiker::BoundingBox::getBottom() const { return mTop - mHeight; }
double turboHiker::BoundingBox::getRight() const { return mLeft + mWidth; }
double turboHiker::BoundingBox::getWidth() const { return mWidth; }
double turboHiker::BoundingBox::getHeight() const { return mHeight; }

bool turboHiker::BoundingBox::empty() const
{
        return getTop() == 0 && getLeft() == 0 && getWidth() == 0 && getHeight() == 0;
}