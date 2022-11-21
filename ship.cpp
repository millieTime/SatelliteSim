/***********************************************************************
 * Source File:
 *    Ship : A player-controlled ship that fires projectiles
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Space Collider, shoots Bullets, can be controlled by keyboard input.
 ************************************************************************/

#include "ship.h"

 /******************************************
  * SHIP : ADVANCE
  * Adjusts the Ship's position, velocity, and direction
  * based on gravity and whether the engine is on.
  *****************************************/
void Ship::advance(double seconds)
{
   // Our parent class handles basic advancing just fine.
   SpaceCollider::advance(seconds);
   
   // All this needs to do is apply acceleration from the engine.
   if (engineOn)
   {
      Acceleration engineAcceleration = Acceleration(direction, 30.0);
      Velocity engineVel = Velocity(0, 0);
      engineVel.applyAcceleration(engineAcceleration, seconds);
      vel.applyAcceleration(engineAcceleration, seconds);
      pos.applyVelAccel(engineVel, engineAcceleration, seconds);
   }
}

/******************************************
 * SHIP : FIRE
 * Emits a bullet in the direction the ship
 * is facing.
 *****************************************/
void Ship::fire(list<SpaceCollider*>& colliders) const
{
   Bullet* b = new Bullet(direction);
   b->launch(pos, vel);
   colliders.push_back(b);
}