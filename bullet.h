/***********************************************************************
 * Header File:
 *    Bullet : A shot fired from the player ship
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Space Collider, and is launched from the player ship.
 ************************************************************************/

#pragma once
#include "timedObject.h"

class Bullet : public TimedObject
{
public:
   Bullet() : Bullet(Angle(0.0)) {}
   Bullet(Angle launchDirection) : TimedObject(launchDirection) { secondsLeft = 2 * TIME_DILATION; }
   virtual double getRadius() const { return 0.5; };
   virtual void draw() const { drawProjectile(pos); };
   virtual void launch(Position& p, Velocity& v)
   {
      // The bullet adds 9000m/s velocity in the direction the ship is facing.
      Velocity launchVel = Velocity(direction, 9000.0);
      launchVel.addVel(v);

      // The bullet spawns in 19 pixels in front of the ship.
      Angle directionOfTravel = Angle(launchVel.getDX(), launchVel.getDY());
      pos = rotate(p, 0.0, 19.0, directionOfTravel.getRadians());
      vel = launchVel;
   }
};