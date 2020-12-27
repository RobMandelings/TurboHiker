//
// Created by Rob Mandelings on 25/12/2020.
//

#include "WindowSize.h"

#include <cassert>

turboHiker::WindowSize::WindowSize(int width, int height) : mWidth(width), mHeight(height) {}

int turboHiker::WindowSize::getWidth() const { return mWidth; }
void turboHiker::WindowSize::setWidth(int width)
{
        assert(width > 0);
        WindowSize::mWidth = width;
}
int turboHiker::WindowSize::getHeight() const { return mHeight; }
void turboHiker::WindowSize::setHeight(int height)
{
        assert(height > 0);
        WindowSize::mHeight = height;
}