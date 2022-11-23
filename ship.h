/***********************************************************************
 * Header File:
 *    Ship : A player-controlled ship that fires bullets
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Space Collider, shoots Bullets, can be controlled by keyboard input.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include "bullet.h"
class Ship :  public SpaceCollider
{
public:
   Ship() : Ship(Position(0.0, 0.0), Velocity(0.0, 0.0)) {}
   Ship(Position pos, Velocity vel) : SpaceCollider(pos, vel) { engineOn = false; }
   virtual void draw() const { drawShip(pos, direction.getRadians(), engineOn); }
   virtual double getRadius() const { return 5.0; }
   virtual void advance(double seconds);
    
   void thrustLeft() { direction.addRadians(-0.1); }
   void thrustRight() { direction.addRadians(0.1); }
   void thrustForward(bool isOn) { engineOn = isOn; }
   void fire(list<SpaceCollider*>& colliders) const;
private:
   bool engineOn;
};

