/***********************************************************************
 * Header File:
 *    Ship : A class representing the Ship.
 * Author:
 *    Leonardo Silva
 * Summary:
 * This class will inheritence all public functions from the
 * flyingObject class, and make sure to create and move the ship
 ************************************************************************/

#ifndef ship_h
#define ship_h

#include "uiDraw.hpp"
#include "flyingObject.hpp"
//#include "point.hpp"
//#include "velocity.hpp"

#define SHIP_SIZE 10
#define THRUST_AMOUNT 0.5
#define ROTATE_AMOUNT 6



class Ship : public FlyingObject
{
private:
    /**********************************************************
     * angle - The angle of the ship in degrees.
     **********************************************************/
    float angle;
    bool isThrusting;


public:
     Ship(); //angle(0) {}
    
    /****************
     *Getters
     ****************/
    float getAngle() const { return angle; }
    void accelerate();
    
    /**************************
    * Setter
    ***************************/
    void setAngle() { this->angle = angle; }
    

    /***************************
     * Public methods
     ****************************/
    void moveToLeft();
    void moveToRight();
    void draw();
    void stopIT();
};

#endif

