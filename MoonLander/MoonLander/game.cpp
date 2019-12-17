/*************************************************************
 * File: game.cpp
 * Author: Br. Burton / modifications by Leonardo Silva
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"

/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded())
   {
   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
    //when my lander goes too far to the topleft (edge) I changed my point 
    //to be less than -200 (-195), and I wrap to the other side (bottomRight) been less than 200 (194)   
    //my point's y will be same
    //I could change my numbers and put my ship wherever I wanted. 
    //Just changing the X's point: bottomright, topleft(adding or subtracting) 
    if (lander.getPoint().getX() < topLeft.getX() + 5)
	       lander.setPoint(Point(bottomRight.getX() - 6, lander.getPoint().getY()));
	//When my lander goes too far to the bottomRight (edge) I changed my point  
    //to be less than 200 (195), and I wrap to the other side ( topLeft) been less than -200 (-194)
    //my point's y will be teh same
    //I could change my numbers and put my ship wherever I wanted. 
    //Just changing the X's point: bottomright, topleft (adding or subtracting)
	if (lander.getPoint().getX() > bottomRight.getX() - 5)
		  lander.setPoint(Point(topLeft.getX() + 6, lander.getPoint().getY()));
   
	lander.draw();
   if (lander.isLanded())
   {
      drawText(Point(), "You have successfully landed!");
   }
   
   if (!lander.isAlive())
   {
      drawText(Point(), "You have crashed!");
   }
   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 5);
   fuelLocation.setY(topLeft.getY() - 5);
   
   drawNumber(fuelLocation, lander.getFuel());

   // draw ground
   ground.draw();
}

