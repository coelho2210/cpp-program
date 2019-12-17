/***********************************************************************
 * Source File:
 *    Velocity : The representation of the Velocity
 * Author:
 *    Leonardo Silva
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/
#include "lander.h"
#include "uiDraw.h"

 // Constructors
Lander::Lander()
{    // setting up where my lander will start (X,X) (Y,Y) 
    // Random function will choose the position between the(parmeters)
  	point = (Point(random(-180, 180), random(50, 200)));
	
	//how much fuel do we have at the begging 
	setFuel(500);

    //are we alive ate the beggining of the game? 
	setAlive(true);
	
    //are we landed at the beggining of the game?
	setLanded(false);
}

/***************************************
* LANDER: CAN THRUST will check if 
* the ship is not Landed, if it is still 
* alive, and if it has fuel 
***************************************/
bool Lander::canThrust() const
{    // the ship will  apply thurst if is "not landed",
	 // still alive, and has fuel (> 0)
	if (alive == true && fuel > 0)
		return true;
	else if (fuel <= 0)
	{
     	//fuel = 0;
		// lander does not thurst if fuel is <= 0
		return false;
	}
	else
		return false;
}

/***************************************
 *Lander: Setters  " setFuel "  
 * The setFuel() will ensure that fuel
 * is never negative and will be call  
 * throughout the class
 ***************************************/
void Lander::setFuel(int fuel)
{
	if (fuel <= 0)
		this->fuel = 0;
	this->fuel = fuel;
}

/***************************************
* LANDER: applyGravity
* will give gravitational force on
* the ship, going down (downwards)
***************************************/
void  Lander:: applyGravity(float gravity)
{
	// velocity(-) a point
	velocity.setDy(velocity.getDy() - 0.1);
}

/***************************************
* LANDER: applyThrustLeft
* will force the ship go to the right
* when we apply force to the left
***************************************/
void Lander::applyThrustLeft()
{
	// velocity (+) a point 1 unit left
	if (canThrust())
	{
		setFuel(fuel - 1);
	    velocity.setDx(velocity.getDx() + 0.1);
	}
	
	}

/***************************************
* LANDER :applyThrustRight
* will force the ship go to the left
* when we apply force to the right
***************************************/
void Lander::applyThrustRight()
{   // velocity (-) a point 1 unit right
	if (canThrust())
	{
		setFuel(fuel - 1);
		velocity.setDx(velocity.getDx() - 0.1);
	}
}

/***************************************
* LANDER :applyThrustBottom
* will force the ship going up when 
* we apply force to the bottom
***************************************/
void Lander:: applyThrustBottom()
{
	if (canThrust())
	{
		setFuel(getFuel() - 3);
		// velocity(+) a point 3 units down
		velocity.setDy(velocity.getDy() + 0.3);
	}
}

/***************************************
* LANDER :Advance will give 
* the lander's moviment when the user
* apply the direction  
***************************************/
void Lander:: advance()
{
	// add velocity to a point,so 
	// that the lander can move
	point.addY(velocity.getDy());
	point.addX(velocity.getDx());
}

/***************************************
* LANDER :Draw
* will draw the ship on the screen
***************************************/
void Lander:: draw() const
{
	//calling drawLander
	drawLander(point);
}

/**********************************************
 * Lander: GetFuel 
*  Will make sure to return the fuel  and make 
* sure that the fuel will be never less than 0
 **********************************************/
int Lander:: getFuel() const 
{
	if (fuel <= 0)
	{
		return 0;
	}
	else 
		return fuel; 

}
