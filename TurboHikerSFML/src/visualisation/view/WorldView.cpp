//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WorldView.h"

turboHikerSFML::WorldView::WorldView(double initialWorldXSize, double initialWorldYSize,
                                     const turboHiker::Vector2d& initialWorldViewCenter)
    : mWorldXSize(initialWorldXSize), mWorldYSize(initialWorldYSize), mWorldViewCenter(initialWorldViewCenter)
{
}

double turboHikerSFML::WorldView::getWorldXSize() const { return mWorldXSize; }
void turboHikerSFML::WorldView::setWorldXSize(double worldXSize) { WorldView::mWorldXSize = worldXSize; }
double turboHikerSFML::WorldView::getWorldYSize() const { return mWorldYSize; }
void turboHikerSFML::WorldView::setWorldYSize(double worldYSize) { WorldView::mWorldYSize = worldYSize; }
const turboHiker::Vector2d& turboHikerSFML::WorldView::getWorldViewCenter() const { return mWorldViewCenter; }
void turboHikerSFML::WorldView::setWorldViewCenter(const turboHiker::Vector2d& worldViewCenter)
{
        WorldView::mWorldViewCenter = worldViewCenter;
}