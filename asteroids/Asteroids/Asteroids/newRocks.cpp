
/***********************************************************************
 * Source File:
 *    NewRock : The representation of the New Rock
 * Author:
 *    Leonardo Silva
 * Summary:
 *    * This class is responsable for adding the parameters to create the
 * NewRock. The functions, and variables are coming inherinting by
 * the Rocks's class
 * In this source file we have:
 * 1  how many points this rock have
 * 2  how should be draw
 * 3   the velocity
 ************************************************************************/

#include "newRocks.hpp"
#include "uiDraw.hpp"

 // Constructors
NewRock::NewRock(Point point) : Rocks(point)
{
    this->position = Point(-165, 45);
    radius = 15;
    numHits = 3;
    velocity.setDx(random(5, 8));
    velocity.setDy(random(-6, 6));
}

void NewRock::draw()
{
    drawToughBird(position, NEW_ROCK_SIZE, numHits);

}

int NewRock::hit(vector<Rocks*> &rocks)
{
    numHits--;
    
    if (numHits == 0)
    {
        kill();
        return 3;
    }
    
    return 1;
}
int NewRock::getRadius()
{
    return NEW_ROCK_SIZE;
}
