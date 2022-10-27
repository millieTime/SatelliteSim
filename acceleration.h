/***********************************************************************
 * Header File:
 *    Acceleration : Represents a 2-dimensional acceleration in the
 *    artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Tracks the components of a 2-dimensional acceleration, and provides
 *    a simple way to add two accelerations together.
 *    Inherits from the Vector2D class.
 ************************************************************************/

#pragma once

#include "vector2D.h"

class Acceleration : public Vector2D
{
public:

   // Default constructor
   Acceleration() : Vector2D() { }
   // Constructs an Acceleration from a horizontal and vertical component
   Acceleration(double ddx, double ddy) : Vector2D(ddx, ddy) { }
   // Constructs an Acceleration from an angle and magnitude
   Acceleration(Angle angle, double magnitude) : Vector2D(angle, magnitude) { }

   // Adds the components of otherAccel to the components of this Acceleration
   virtual void addAcceleration(const Acceleration& accel) { addVector(accel); };
};
