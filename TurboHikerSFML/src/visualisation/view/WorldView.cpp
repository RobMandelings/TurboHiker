//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WorldView.h"

turboHikerSFML::WorldView::WorldView(double initialWorldXSize, double initialWorldYSize,
                                     const turboHiker::Vector2d& initialWorldViewCenter)
    : mWorldXSize(initialWorldXSize), mWorldYSize(initialWorldYSize), mWorldViewCenter(initialWorldViewCenter)
{
}

double turboHikerSFML::WorldView::getWorldViewWidth() const { return mWorldXSize; }
void turboHikerSFML::WorldView::setWidth(double worldXSize) { WorldView::mWorldXSize = worldXSize; }
double turboHikerSFML::WorldView::getWorldViewHeight() const { return mWorldYSize; }
void turboHikerSFML::WorldView::setHeight(double worldYSize) { WorldView::mWorldYSize = worldYSize; }
const turboHiker::Vector2d& turboHikerSFML::WorldView::getWorldViewCenter() const { return mWorldViewCenter; }
void turboHikerSFML::WorldView::setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter)
{
        WorldView::mWorldViewCenter = worldViewCenter;
}