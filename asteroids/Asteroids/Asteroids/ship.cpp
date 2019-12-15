/*************************************************************
 * Source: Ship.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the function bodies for the ship class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/
#include "ship.hpp"
#define deg2rad(value) ((M_PI / 180) * (value))
#define M_PI      3.14159265359
#include<math.h>
/*****************************
* Ship: Constructor
*
******************************/
Ship::Ship()
{
    isThrusting = false;
    angle = 0;
}


/******************************
*Ship: DRAW
*
******************************/
void Ship::draw()
{
     drawShip(position, angle, isThrusting);
     
     if (isThrusting)
    {
        isThrusting = false;
    }
}

/******************************
*Ship: MoveLeft
*
******************************/

void Ship::moveToLeft()
{
    this->angle += ROTATE_AMOUNT;
}


/******************************
*Ship: MoveRight
*
******************************/
void Ship::moveToRight()
{
    this->angle -= ROTATE_AMOUNT;
}

/*************************************************
* Function: Accelerate
* Purpose: Add velocity to thrust in the direction
* the ship is facing
* accelerate makes Velocity change !
***************************************************/
void Ship::accelerate()
{
    isThrusting = true;
       // testing the code below if will works, but  that is very complicated way!! :(
    
      //setVelocity((velocity.getDx() + THRUST_AMOUNT) * cos(deg2rad(angle + 90)),
     //(velocity.getDy() + THRUST_AMOUNT) * sin(deg2rad(angle + 90)));
    
    // determine ships velocity
    float dx = THRUST_AMOUNT * (cos(M_PI / 180.0 * (angle - 90)));
    float dy = THRUST_AMOUNT * (-sin(M_PI / 180.0 * (angle - 90)));
    // change ships velocity
    velocity.setDx(velocity.getDx() - dx);
    velocity.setDy(velocity.getDy() + dy);
}


void Ship::stopIT()
{
    setVelocity(0.0, 0.0);

}
