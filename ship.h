/***********************************************************************
 * Header File:
 *    Ship : A player-controlled ship that fires bullets
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    Is a Space Collider, shoots Bullets, can be controlled by keyboard input.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include "bullet.h"
class Ship :  public SpaceCollider
{
public:
    // Default Constructor for Ship
   Ship() : Ship(Position(0.0, 0.0), Velocity(0.0, 0.0)) {}
    // Non-Default Constructor for Ship
   Ship(Position pos, Velocity vel) : SpaceCollider(pos, vel) { engineOn = false; }
    // Draw Ship
   virtual void draw() const { drawShip(pos, direction.getRadians(), engineOn); }
    // Getter for Ship Radius
   virtual double getRadius() const { return 5.0; }
    // Advance Ship
   virtual void advance(double seconds);
    // Thrust Left of Ship
   void thrustLeft() { direction.addRadians(-0.1); }
    // Thrust Right of Ship
   void thrustRight() { direction.addRadians(0.1); }
    // Engage main thrust of Ship
   void thrustForward(bool isOn) { engineOn = isOn; }
    // Fire bullets
   void fire(list<SpaceCollider*>& colliders) const;
private:
   bool engineOn;
};

