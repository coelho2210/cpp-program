/***********************************************************************
 * Header File:
 *    LargeRocks : A class representing the Largerocks
 * Author:
 *    Leonardo Silva
 * Summary:
 ** This class is responsable for adding the parameters to create the
 * largeRocks. The functions, and variables are coming inherinting by
 * the Rocks's class
 ************************************************************************/

#ifndef LARGEROCK_H
#define LARGEROCK_H
#include "point.hpp"
#include "rocks.hpp"


class LargeRocks :public Rocks
{
private:
    
    // I will implement a score later
    //int numHits;

public:

    //constructor
    LargeRocks(Point point);


    //methods public
    void draw();
    int hit(vector<Rocks*>&rocks);
    int getRadius();
};

#endif

