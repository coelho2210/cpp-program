/***********************************************************************
 * Header File:
 *    Velocity: A class representing the velocity from the Asteroid
 * game
 * Author:
 *    Leonardo Silva
 * Summary:
 * This class will make sure to give velocity to all the objects in this
 * game.
 ************************************************************************/
#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity {
private:
    float dx;
    float dy;


public:
    //Constructors
    Velocity();
    Velocity(float dx, float dy);

    //Getters
    float getDx() const { return dx; }
    float getDy() const { return dy; }

    //Setters
    void setDx(float dx) { this->dx = dx; }
    void setDy(float dy) { this->dy = dy; }

};



#endif /* velocity_h */

