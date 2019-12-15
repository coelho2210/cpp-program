/*************************************************************
 * Source: largeRocks.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the largeRocks class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 ********************************************************************/

#include "largerocks.hpp"
#include "rocks.hpp"
#include "uiDraw.hpp"
#include "mediumRocks.hpp"
#include "smallRocks.hpp"


 // Put your Rock methods here
LargeRocks::LargeRocks(Point point)
{
    this->position = point;
}

void LargeRocks::draw()
{
    drawLargeAsteroid(position, rotation);
    rotation += BIG_ROCK_SPIN;
}

int LargeRocks::hit(vector<Rocks*>&rocks)
{
    //kill the rocks
     kill();

    // create three new rocks
    Rocks* rock1;
    rock1 = new MediumRocks(position);
    rock1->getVelocity().setDy(velocity.getDy() + 1);
    rock1->getVelocity().setDx(velocity.getDx());
    rocks.push_back(rock1);

    Rocks* rock2;
    rock2 = new MediumRocks(position);
    rock2->getVelocity().setDy(velocity.getDy() - 1);
    rock2->getVelocity().setDx(velocity.getDx());
    rocks.push_back(rock2);
    
    Rocks* rock3;
    rock3 = new SmallRocks(position);
    rock3->getVelocity().setDy(velocity.getDy());
    rock3->getVelocity().setDx(velocity.getDx() + 2);
    rocks.push_back(rock3);
    
    return 0;
}

int LargeRocks::getRadius()
{
    return BIG_ROCK_SIZE;
}

