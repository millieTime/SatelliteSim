/***********************************************************************
 * Header File:
 *    Acceleration : Represents a 2-dimensional acceleration in the
 *    satellite simulation
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    Tracks the components of a 2-dimensional acceleration, and provides
 *    a simple way to add two accelerations together
 ************************************************************************/
#pragma once
#include "angle.h"

class Acceleration
{
public:

   // Default constructor
   Acceleration() : ddx(0.0), ddy(0.0) { }
   // Constructs an Acceleration from a horizontal and vertical component
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) { }
   // Constructs an Acceleration from an angle and magnitude
   Acceleration(Angle angle, double magnitude);

   // Getters
   double getDDX() const { return ddx; }
   double getDDY() const { return ddy; }

   // Setters
   void setDDX(double newDDX) { ddx = newDDX; }
   void setDDY(double newDDY) { ddy = newDDY; }

   // Adds the components of otherAccel to the components of this Acceleration
   virtual void addAcceleration(const Acceleration& accel) 
   {
      ddx += accel.getDDX();
      ddy += accel.getDDY();
   };

private:
   double ddx;  // The horizontal component
   double ddy;  // The vertical component
};
