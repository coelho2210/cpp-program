
/***********************************************************************
 * Header File:
 *    NewRocks : A class representing the New Rock
 * Author:
 *    Leonardo Silva
 * Summary:
 * * This class is responsable for adding the parameters to create the
 * newRock. The functions, and variables are coming inherinting by
 * the Rocks's class
 ************************************************************************/

#ifndef NEWROCKS_H
#define NEWROCKS_H
#include "point.hpp"
#include "rocks.hpp"


class NewRock :public Rocks
{
private:
    int numHits;

public:

    //constructor
    NewRock(Point point);

    //methods public
    void draw();
    int hit(vector<Rocks*> &rocks);
    int getRadius();
};

#endif
