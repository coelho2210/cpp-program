/*************************************************************
 * Header: game.h
 * Author: Leonardo Silva
 *
 * Description: The game of Asteroids. This class holds each piece
 *  of the game (rocks, bullets, ship, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <limits>
#include <algorithm>
#include "game.hpp"
#include "uiDraw.hpp"
#include "uiInteract.hpp"
#include "point.hpp"
#include "rocks.hpp"
#include "largeRocks.hpp"
#include "rocks.hpp"
#include "smallRocks.hpp"
#include "ship.hpp"
#include "velocity.hpp"
#include "bullet.hpp"

#define CLOSE_ENOUGH 15
#define SHIP_RADIUS  10

/********************************
* Game
* Description: Contains the definition
* of the game class.
**********************************/

class Game
{

 private:
    // The coordinates of the screen
   Point topLeft;
   Point bottomRight;

   // I want to implement the score in this game
   int score;

   bool continueGame; // This varible willbe responsable to continue the game when it finished

   //vector
   std::vector<Bullet> bullets;
   std::vector<Rocks*> rocks;
   
   //Ship ship;
   Ship * ship;
   
/*************************************************
* Private methods to help with the game logic.
*************************************************/
 bool isOnScreen(const Point & point);
 void advanceBullets();
 void advanceRocks();
 void createRocks();
 float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
 void handleCollisions();
 void cleanUpZombies();

 
 public:

     //constructor
    // Initializes the game
     Game(Point t1, Point br);
     ~Game();
     //Function: handleInput
     // Description : Takes actions according to whatever
     //Keys the user has pressed.
     void handleInput(const Interface & ui);

     //Function: advance
     //Description : Move everything forward one
     //step in time.
     void advance();

     //Function: draw
     //Description : draws everything for the game.
     void draw(const Interface & ui);
 
};

#endif /* GAME_H */


