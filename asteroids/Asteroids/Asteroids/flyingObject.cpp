/*************************************************************************
 * Source: flyingObject.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the flyingObejct class.
 *
 Summary:
 * This class is responsable to pass functions and variables
 * to a different classes in this program.
 ********************************************************************/

#include "flyingObject.hpp"
#include "point.hpp"
#include "velocity.hpp"
#include <iostream>


  // Constructors
FlyingObject::FlyingObject()
{
    alive = true;
    position.setX(0.0);
    position.setY(0.0);
    velocity.setDx(0.0);
    velocity.setDy(0.0);

}

FlyingObject::FlyingObject(Point point)
{
    alive = true;
    this->position.setX(point.getX());
    this->position.setY(point.getY());
    velocity.setDx(0.0);
    velocity.setDy(0.0);

}

    // just testing
    //std::cerr << "Point of rock = (" << position.getX() << ", " << position.getY() << ")\n";


void FlyingObject::advance()
{
    //wrap rocks-bullets-ship
    wrap();
    // add velocity to a point,so
    // that the rocks can move
    position.addY(velocity.getDy());
    position.addX(velocity.getDx());

}

void FlyingObject::wrap()
{
    // wrap my rocks/bullet/ship
     if (position.getX() < -200)
    {
      position.setX(200);
     }
    else if (position.getX() > 200)
    {
      position.setX(-200);
    }
    else if (position.getY() < -200)
    {
      position.setY(200);
    }
    else if (position.getY() > 200)
    {
      position.setY(-200);
    }
}



