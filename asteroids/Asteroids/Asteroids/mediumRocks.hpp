/***********************************************************************
 * Header File:
 *    MediumRocks : A class representing the MediumRocks
 * Author:
 *    Leonardo Silva
 * Summary:
 ** This class is responsable for adding the parameters to create the
 * mediumRocks. The functions, and variables are coming inherinting by
 * the Rocks's class
 ************************************************************************/

#ifndef MIDIUMROCKS_H
#define MIDIUMROCKS_H
#include "point.hpp"
#include "ROCKS.hpp"


class MediumRocks :public Rocks
{
private:


public:

    //constructor
    MediumRocks(Point point);



    //methods public
    void draw();
    int hit(vector<Rocks*>&rocks);
    int getRadius();
};

#endif

