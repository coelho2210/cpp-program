/***********************************************************************
 * Header File:
 *    LANDER : A class representing the Lander 
 * Author:
 *    Leonardo Silva
 * Summary:
 *    Everything you needed to know about the lander "I hope so" lol 
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"



class Lander {
private:
	Point point;
	Velocity velocity;
	bool alive;
	bool landed;
	int fuel;
	

public:
	// Constructors
	Lander();
	
	// Getters
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return velocity; }
	int getFuel() const;
	bool isAlive() const { return alive; }
	bool isLanded() const { return landed; }
	bool canThrust()const;
	
	// Setters
	void setPoint(Point p) { point = p; }
	void setLanded(bool landed) { this->landed = landed; }
	void setAlive(bool alive) { this-> alive = alive;}
	void setFuel(int fuel);
	
	//  public method 
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw() const;
	
	
};

#endif