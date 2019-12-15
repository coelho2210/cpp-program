
/***********************************************************************
 * Header File:
 *    Rocks : A class representing the Rocks. This class will pass the
 *    public variables and the functions to  all Rocks in the program.
 * Author:
 *    Leonardo Silva
 * Summary:
 * This class will inheritence all public functions from the
 * flyingObject class, and make sure to pass all the necessary
 * informations to the 3 derived rocks.
 ************************************************************************/
#ifndef rocks_h
#define rocks_h

#include "point.hpp"
#include "flyingObject.hpp"
#include "uiDraw.hpp"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4
#define NEW_ROCK_SIZE 15

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10


class Rocks : public FlyingObject
{
protected:
    int radius;
    int rotation;

public:

    //constructor
    Rocks();
    Rocks(Point &point);
    

    
    //methods public
    virtual void draw()    = 0;
    virtual int  hit(vector<Rocks*> &rocks)   = 0;
    virtual int getRadius() = 0;
};

#endif




