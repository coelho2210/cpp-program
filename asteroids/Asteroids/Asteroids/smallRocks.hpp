/***********************************************************************
 * Header File:
 *    SmallRocks : A class representing the SmallRocks
 * Author:
 *    Leonardo Silva
 * Summary:
 ** This class is responsable for adding the parameters to create the
 * smallRocks. The functions, and variables are coming inherinting by
 * the Rocks's class
 ************************************************************************/

#ifndef SMALLROCKS_H
#define SMALLROCKS_H
#include "point.hpp"
#include "rocks.hpp"


class SmallRocks :public Rocks
{


public:

    //constructor
    SmallRocks(Point point);

    //methods public
    void draw();
    int hit(vector<Rocks*>&rocks);
    int getRadius();
};

#endif
