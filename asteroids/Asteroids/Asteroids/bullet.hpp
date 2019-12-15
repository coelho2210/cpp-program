
/***********************************************************************
 * Header File:
 *    Bullet : A class representing the bullet in this code.
 * Author:
 *    Leonardo Silva
 * Summary:
 * This class will inheritence the variables and the functions
 * from the flyingObject.
 ************************************************************************/


#ifndef bullet_h
#define bullet_h
#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "point.hpp"
#include "flyingObject.hpp"
#include "uiDraw.hpp"


class Bullet : public FlyingObject
{
private:
    float angle;
    int life; // how long is lived based on the number of fremes
public:

    //constructor
    Bullet();

    //methods public
    void draw();
    void advance(); // virtual
     void fire(Point point, float angle, Velocity velocity);
    void fireManyBullets(Point point, float angle, Velocity velocity,vector<Bullet>&bullets);
};

#endif



