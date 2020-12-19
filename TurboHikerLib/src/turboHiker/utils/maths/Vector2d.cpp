//
// Created by RobMa on 19/12/2020.
//

#include "Vector2d.h"

turboHiker::Vector2d::Vector2d(double xCoord, double yCoord) : xCoord(xCoord), yCoord(yCoord) {}

turboHiker::Vector2d turboHiker::Vector2d::operator+(const turboHiker::Vector2d& vector2D) const
{
        return Vector2d(this->xCoord + vector2D.xCoord, this->yCoord + vector2D.yCoord);
}
turboHiker::Vector2d turboHiker::Vector2d::operator-(const turboHiker::Vector2d& vector2D) const
{
        return Vector2d(this->xCoord - vector2D.xCoord, this->yCoord - vector2D.yCoord);
}
turboHiker::Vector2d& turboHiker::Vector2d::operator+=(const turboHiker::Vector2d& vector2D)
{
        this->xCoord + vector2D.xCoord;
        this->yCoord + vector2D.yCoord;
        return *this;
}
turboHiker::Vector2d& turboHiker::Vector2d::operator-=(const turboHiker::Vector2d& vector2D)
{
        this->xCoord - vector2D.xCoord;
        this->yCoord - vector2D.yCoord;
        return *this;
}
