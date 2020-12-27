//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WorldView.h"

turboHiker::WorldView::WorldView(double initialWorldXSize, double initialWorldYSize,
                                     const turboHiker::Vector2d& initialWorldViewCenter)
    : mWorldXSize(initialWorldXSize), mWorldYSize(initialWorldYSize), mWorldViewCenter(initialWorldViewCenter)
{
}

double turboHiker::WorldView::getWorldViewWidth() const { return mWorldXSize; }
void turboHiker::WorldView::setWidth(double worldXSize) { WorldView::mWorldXSize = worldXSize; }
double turboHiker::WorldView::getWorldViewHeight() const { return mWorldYSize; }
void turboHiker::WorldView::setHeight(double worldYSize) { WorldView::mWorldYSize = worldYSize; }
const turboHiker::Vector2d& turboHiker::WorldView::getWorldViewCenter() const { return mWorldViewCenter; }
void turboHiker::WorldView::setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter)
{
        WorldView::mWorldViewCenter = worldViewCenter;
}