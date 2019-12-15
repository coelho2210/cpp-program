/*************************************************************
 * Source: game.cpp
 * Author: Leonardo Silva
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/



// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

#include "game.hpp"
#include "uiDraw.hpp"
#include "uiInteract.hpp"
#include "point.hpp"
#include "rocks.hpp"
#include "largeRocks.hpp"
#include "mediumRocks.hpp"
#include "newRocks.hpp"
#include "smallRocks.hpp"
#include "ship.hpp"
#include "flyingObject.hpp"


#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 25


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br)
    : topLeft(tl), bottomRight(br)
{
   continueGame = false; // This varible will be responsable to continue the game when it finished

      //  I am planning appling score in this game
    score = 0;
    
    // call create Rocks ( begining with 5 BiG Rocks)
   createRocks();

   
    
    // not allocated yet, point it to NULL
    ship = NULL;
    // if we fail to allocate don't throw an error
    // set the pointer  to Null
    // in this moment of my code, I could use the Try/Catch std::bad_alloc
    ship = new(nothrow) Ship();
}
/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
    if (ship != NULL)
    {
        delete ship;
        ship = NULL; // avoid zombie pointer
    }
    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i] != NULL)
        {
            delete rocks[i];
            rocks[i] = NULL;
        }
    }
}


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
    if ( continueGame == true)
    {
        // call create Rocks ( begining with 5 BiG Rocks)
        if (rocks.size() == 0)
        {
            createRocks();
        }
        if (ship == NULL)
        {
            ship = new Ship;
        }
        continueGame = false;
    }
    
    // advance all Rocks
    advanceRocks();
    
    if(ship != NULL && ship->isAlive())
        ship->advance();
    
    // advance bullets
    advanceBullets();
    // this handle rocks to ship collisions and
    // bullets to rock collisions
    handleCollisions();
    // delete rocks and bullets
    cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
    // Move each of the bullets forward if it is alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i].advance();

            if (!isOnScreen(bullets[i].getPoint()))
            {
                // the bullet has left the screen
                bullets[i].kill();
            }

        }
    }
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 *
 **************************************************************************/
void Game::advanceRocks()
{
    
        for(vector <Rocks*> ::iterator it = rocks.begin(); it != rocks.end(); ++it)

        {
            if ((*it)->isAlive())
            {
                (*it)->advance();
            }
        }

    
}



/************************************************
* GAME : Create Rocks
*
*************************************************/
void Game::createRocks()
{
    
    {
        Point point(random(topLeft.getX(), bottomRight.getX()), random(bottomRight.getY(), topLeft.getY()));
        Rocks* addRock;
        addRock = new NewRock(point);
        rocks.push_back(addRock);
    }
    for (int i = 0; i < 5; i++)
    {
        
        Point point(random(topLeft.getX(), bottomRight.getX()), random(bottomRight.getY(), topLeft.getY()));
        Rocks* addNewRock;
        addNewRock = new LargeRocks(point);
        rocks.push_back(addNewRock);

    }


}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point & point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
        && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
        && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
        && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock, ship and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
    //creating a Temporary vector so I will not add things in my
    // original vector during the loop
    vector<Rocks*>newRocks;
    //this will handle  the Collissions between the Rocks and the Ship
    for (int j = 0; j < rocks.size(); j++)
    {
        //when the radius(distance) betewwen the ship and the rock  is less than their radius
        // (SHiP + rocks) the rocks dies
        if (ship != NULL && getClosestDistance(*rocks[j], *ship) <= SHIP_RADIUS + rocks[j]->getRadius())

        {
            //the rock will died when hit the ship
            rocks[j]->hit(newRocks);

            // The ship will died when hit the rock
            ship->kill();
        }
        // this will handle the Collissions between the Rocks and and the bullets
        for (int i = 0; i < bullets.size(); i++)
        {
            // bullets should be alive and  the radius

            if (bullets[i].isAlive() && getClosestDistance(*rocks[j], bullets[i]) <= rocks[j]->getRadius())
            {
                //this is important because anytime when the
                // rocks and the bullets collides they are going to be killed
                // getting score when hit the "asteroid-toughbird"
                score += rocks[j]->hit(rocks);
                bullets[i].kill();
            }
        }
    }
    for (int i = 0; i < newRocks.size(); i++)
    {
        
        rocks.push_back(newRocks[i]);
    }
}



/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list)
 **************************************************************************/
void Game::cleanUpZombies()
{
    vector<Bullet>::iterator iteratorBullet = bullets.begin();
    while (iteratorBullet != bullets.end())
    {
        Bullet bullet = *iteratorBullet;

        if (!bullet.isAlive())
        {
            iteratorBullet = bullets.erase(iteratorBullet);
        }
        else
        {
            iteratorBullet++;
        }
    }
    // looping through the rocks
    for (vector <Rocks*> ::iterator it = rocks.begin(); it != rocks.end(); )

    {    // if is  not alive
        if (!(*it)->isAlive())
        {
            // This will delete the memory and remove it from the vector's rocks.
            delete (*it);
            it = rocks.erase(it);
        }
        else
        {    // else increment it
            ++it;
        }

    }
    //check if ship is not NULL and not alive
    if (ship != NULL && !ship->isAlive())
    {
        // delete ship!
        delete ship;
        // avoid zombie pointer
        ship = NULL;
    }

}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
    // make sure that ship is not pointing to null,
    // so we don't get a segmentation fault
    if (ship != NULL && ship->isAlive())
    {
        // Change the direction of the ship
        if (ui.isLeft())
        {
            ship->moveToLeft();
        }
        // Change the direction of the ship
        if (ui.isRight())
        {
            ship->moveToRight();
        }
        //this function will stop the ship when I hit the Down bottom
        if (ui.isDown())
        {
            ship->stopIT();

        }
        // Check for "Spacebar"
        if (ui.isSpace() && ship->isAlive())
        {
            Bullet newBullet;
            newBullet.fire(ship->getPoint(), ship->getAngle(), ship->getVelocity());


            bullets.push_back(newBullet);
        }

        if (ui.isT() && ship->isAlive())
        {
             Bullet bullet2;
             bullet2.fireManyBullets(ship->getPoint(), ship->getAngle(), ship->getVelocity(),bullets);
        }
        //when the user presses up, call the give the accelerate function
        // this function will makes the velocity change!
        if (ui.isUp())
        {
            ship->accelerate();
        }
        
    }

    if (ui.isContinue() && continueGame == false)
        continueGame = true;
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface & ui)
{
    if (ship == NULL || rocks.size() == 0)
    {
        // draw these messages when ship die or  all rocks die
        drawText(Point(-180, 10), "GAME OVER! TRY USING THE BOTTOM ' T ' TO SURVIVE");
        drawText(Point(10, -90), " Restart Game - Click 'C' !!!");

    }

    for (vector <Rocks*> ::iterator it = rocks.begin(); it != rocks.end(); ++it)
    {
        (*it)->draw();
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
    }
    // is ship is playing "alive"
    if (ship != NULL && ship->isAlive())
    {
        // draw the ship
        ship->draw();
    }
        
    //  I want implement score in thsi game!
    // Put the score on the screen
    Point scoreLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 5);

    drawNumber(scoreLocation, score);

}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
 
 float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
 {
    // find the maximum distance traveled
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
       Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                      obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
       Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                      obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

       float xDiff = point1.getX() - point2.getX();
       float yDiff = point1.getY() - point2.getY();

       float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

       distMin = min(distMin, distSquared);
    }

    return sqrt(distMin);
 }


