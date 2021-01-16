//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WorldView.h"

turboHiker::WorldView::WorldView(double width, double height,
                                     const turboHiker::Vector2d& worldViewCenter)
    : mWidth(width), mHeight(height), mWorldViewCenter(worldViewCenter)
{
}

double turboHiker::WorldView::getWorldViewWidth() const { return mWidth; }
void turboHiker::WorldView::setWidth(double width) { WorldView::mWidth = width; }
double turboHiker::WorldView::getWorldViewHeight() const { return mHeight; }
void turboHiker::WorldView::setHeight(double height) { WorldView::mHeight = height; }
const turboHiker::Vector2d& turboHiker::WorldView::getWorldViewCenter() const { return mWorldViewCenter; }
void turboHiker::WorldView::setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter)
{
        WorldView::mWorldViewCenter = worldViewCenter;
}