/*************************************************************
 * Source: Rocks.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the Rocks class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 ********************************************************************/


#include "rocks.hpp"

// Put your Rock methods here
Rocks::Rocks()
{
    rotation = (random(0, 360));
    velocity.setDx(random(-1, 2));
    velocity.setDy(random(-1, 2));
}

Rocks::Rocks(Point &point)
{

}

