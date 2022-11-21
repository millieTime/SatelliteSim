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
   Bullet() : TimedObject() { secondsLeft = 70; }
   Bullet(Angle launchDirection) : TimedObject() { direction = launchDirection; secondsLeft = 70; }
   virtual double getRadius() const { return 0.5; };
   virtual void draw() const { drawProjectile(pos); };
   virtual void launch(Position p, Velocity v)
   {
      // The bullet adds 9000m/s velocity in the direction the ship is facing.
      Velocity launchVel = Velocity(direction, 9000.0);
      v.addVel(launchVel);

      // The bullet spawns in 19 pixels in front of the ship.
      pos = rotate(p, 0.0, 19.0, direction.getRadians());
      vel = v;
   }
};