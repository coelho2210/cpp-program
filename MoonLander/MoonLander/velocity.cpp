/***********************************************************************
 * Source File:
 *    Velocity : The representation of the Velocity
 * Author:
 *    Leonardo Silva
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/
#include "velocity.h"

 // Constructors
Velocity::Velocity()
{
	setDx(0.0);
	setDy(0.0);
}

Velocity::Velocity(float dx, float dy)
{
	setDx(dx);
	setDy(dy);
}


