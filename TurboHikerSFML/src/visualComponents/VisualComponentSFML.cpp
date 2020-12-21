//
// Created by RobMa on 21/12/2020.
//

#include "VisualComponentSFML.h"

#include "WindowDrawer.h"

void turboHikerSFML::VisualComponentSFML::draw(const turboHiker::Vector2d& worldLocation) const {
        // Okay nice! So the pointer itself does not change (its value might), meaning that the class is still considered 'const' and the functions as well
        // TODO use the transformation class to get the pixel values to draw on screen
        mWindowDrawer->drawOnWindow(*this, worldLocation);
}