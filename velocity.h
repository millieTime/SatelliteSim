/***********************************************************************
 * Header File:
 *    Velocity : Represents a 2-dimensional velocity in the
 *    artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Tracks the components of a 2-dimensional velocity, and provides
 *    a simple way to apply an acceleration over time.
 *    Inherits from the Vector2D class.
 ************************************************************************/

#pragma once

#include "vector2D.h"

class Velocity : public Vector2D
{
public:

   // Default constructor
   Velocity() : Vector2D() {}
   // Construct from components
   Velocity(double x, double y) : Vector2D(x, y) { }
   // Construct from angle and magnitude
   Velocity(Angle angle, double mag) : Vector2D(angle, mag) {}

   // Apply an acceleration to this velocity for the specified amount of time
   virtual void applyAcceleration(const Vector2D &accel, double time);
};