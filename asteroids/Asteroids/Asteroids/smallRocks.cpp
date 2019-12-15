/*************************************************************
 * Source: smallRocks.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the smallRocks class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 ********************************************************************/

#include "smallrocks.hpp"
#include "rocks.hpp"
#include "uiDraw.hpp"
 // Put your Rock methods here

SmallRocks::SmallRocks(Point point)
{
    this->position = point;
}

void SmallRocks::draw()
{
    drawSmallAsteroid(position, rotation);
    rotation += SMALL_ROCK_SPIN;
}


int SmallRocks::hit(vector<Rocks*>&rocks)
{
    //kill the rocks
    kill();
    return 0;
}

int SmallRocks::getRadius()
{
    return SMALL_ROCK_SIZE;
}

