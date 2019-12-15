/*************************************************************
 * Source: mediumRocks.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the mediumRocks class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 ********************************************************************/


#include "mediumrocks.hpp"
#include "rocks.hpp"
#include "uiDraw.hpp"
#include "smallRocks.hpp"
 // Put your Rock methods here

MediumRocks::MediumRocks(Point point)
{
    this->position = point;
}

void MediumRocks::draw()
{
    drawMediumAsteroid(position, rotation);
    rotation += MEDIUM_ROCK_SPIN;
}


int MediumRocks::hit(vector<Rocks*>&rocks)
{
    //kill the rocks
    kill();

    // create three new rocks
    Rocks* rockSmall;
    rockSmall = new SmallRocks(position);
    //rockSmall->getVelocity().setDx(4);
    rocks.push_back(rockSmall);

    Rocks* small;
    small = new SmallRocks(position);
    rocks.push_back(small);
    return 0;
}


int MediumRocks::getRadius()
{
    return MEDIUM_ROCK_SIZE;
}

