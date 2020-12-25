//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WindowSize.h"

#include <cassert>

turboHikerSFML::WindowSize::WindowSize(int width, int height) : mWidth(width), mHeight(height) {}

int turboHikerSFML::WindowSize::getWidth() const { return mWidth; }
void turboHikerSFML::WindowSize::setWidth(int width)
{
        assert(width > 0);
        WindowSize::mWidth = width;
}
int turboHikerSFML::WindowSize::getHeight() const { return mHeight; }
void turboHikerSFML::WindowSize::setHeight(int height)
{
        assert(height > 0);
        WindowSize::mHeight = height;
}