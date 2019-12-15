/***********************************************************************
 * Source File:
 *    Bullet : The representation of the Bullet from the Game
 * Author:
 *    Leonardo Silva
 * Summary:
 *    Everything we need to know about the bullets inside of the game
 ************************************************************************/
#include "bullet.hpp"
//#define M_PI  3.14159265359
#define deg2rad(value) ((M_PI / 180) * (value))

// Put your bullet methods here

Bullet::Bullet()
{
    life = 0;
}

void Bullet::fire(Point point, float angle, Velocity velocity)
{
    position = point;
    //set the point, velocity and the angle to the bullets
    this->velocity.setDx(velocity.getDx() + BULLET_SPEED * (cos(deg2rad(angle + 90))));
    this->velocity.setDy(velocity.getDy() + BULLET_SPEED * (sin(deg2rad(angle + 90))));
}

void Bullet::draw()
{
    drawDot(position);
}


void Bullet::advance()
{
    if (++life < 40)
    {
        //wrap rocks-bullets-ship
        wrap();
        // add velocity to a point,so
        // that the rocks can move
        position.addY(velocity.getDy());
        position.addX(velocity.getDx());
    }
    else
    {
      kill();
    }
}


void Bullet::fireManyBullets(Point point, float angle, Velocity velocity, vector<Bullet>&bullets)
{
    position = point;
    
    //set the point, velocity and the angle to the bullets
    for (int i = 0; i < 100; i++)
    {
        Bullet bullet;
        bullet.velocity.setDx(velocity.getDx() + BULLET_SPEED * (cos(deg2rad(angle + 90))));
        bullet.velocity.setDy(velocity.getDy() + BULLET_SPEED * (sin(deg2rad(angle + 90))));
        bullet.setPoint(point);
        angle += 3.6;
        bullets.push_back(bullet);

    }

}



