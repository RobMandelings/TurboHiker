//
// Created by RobMa on 28/12/2020.
//

#include "Color.h"
#include <cmath>

namespace turboHikerSFML {
Color::Color(double red, double green, double blue) : mRed(red), mGreen(green), mBlue(blue) {}

void Color::setRed(double red)
{
        mRed = red;
        if (mRed > 1) {
                mRed = 1;
        } else if (mRed < 0) {
                mRed = 0;
        }
}
void Color::setGreen(double green)
{
        mGreen = green;
        if (mGreen > 1) {
                mGreen = 1;
        } else if (mGreen < 0) {
                mGreen = 0;
        }
}
void Color::setBlue(double blue)
{
        mBlue = blue;
        if (mBlue > 1) {
                mBlue = 1;
        } else if (mBlue < 0) {
                mBlue = 0;
        }
}
double Color::getRed() const { return mRed; }
double Color::getGreen() const { return mGreen; }
double Color::getBlue() const { return mBlue; }
sf::Color Color::getSFMLColor() const
{
        return sf::Color(std::round(mRed * 255), std::round(mGreen * 255), std::round(mBlue * 255));
}
} // namespace turboHikerSFML
