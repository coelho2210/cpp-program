/***********************************************************************
 * Header File:
 *    FlyingObject : A class representing the FlyingObject
 * Author:
 *    Leonardo Silva
 * Summary:
 * This class is responsable to pass functions and variables
 * to a different classes in this program.
 ************************************************************************/
#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.hpp"
#include "velocity.hpp"
#include <vector>
using namespace std;

class FlyingObject
{
protected:
    Point position;
    Velocity velocity;
    bool alive;

public:
    //constructor
    FlyingObject();
    FlyingObject(Point point);

    //getters
    Point getPoint() const { return position; }
    Velocity getVelocity() const { return velocity; }
    bool isAlive() { return alive; }
    
    
    //setters
    void setPoint(float x, float y) { position.setX(x); position.setY(y); }
    void setVelocity(float dx, float dy) { velocity.setDx(dx); velocity.setDy(dy); }
    void setPoint(Point position) { this->position = position; }
    void setVelocity(Velocity velocity) { this->velocity = velocity;}
    void setAlive(bool alive) { this->alive = alive; }

    //methods publics
    void kill() { alive = false; }
    virtual void  advance();
    void wrap();
    virtual void draw() = 0;
};




#endif /* flyingObject_h */

