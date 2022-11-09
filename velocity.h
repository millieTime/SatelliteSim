/***********************************************************************
 * Header File:
 *    Velocity : Represents a velocity in the orbiter simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Tracks the components of a 2-dimensional velocity, and provides
 *    a simple way to apply an acceleration over time.
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "angle.h"

class Velocity
{
public:

   // Default constructor
   Velocity() : dx(0.0), dy(0.0) {}
   // Construct from components
   Velocity(double dx, double dy) : dx(dx), dy(dy) { }
   // Construct from angle and magnitude
   Velocity(Angle angle, double mag);

   // Getters
   double getDX() const { return dx; }
   double getDY() const { return dy; }

   // Setters
   void setDX(double newDX) { dx = newDX; }
   void setDY(double newDY) { dy = newDY; }

   // Apply an acceleration to this velocity for the specified amount of time
   // velocity += acceleration * time
   void applyAcceleration(const Acceleration& accel, double time)
   {
      setDX(dx + accel.getDDX() * time);
      setDY(dy + accel.getDDY() * time);
   };

private:
   double dx; // horizontal component
   double dy; // vertical component
};