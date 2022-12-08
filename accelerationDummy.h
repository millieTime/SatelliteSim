/***********************************************************************
 * Header File:
 *    Acceleration Dummy : A dummy for the acceleration class to be used in testing.
 * Author:
 *    Preston Millward
 * Summary:
 *    The acceleration class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "acceleration.h"
#include <cassert>

class AccelerationDummy : public Acceleration
{
public:
   AccelerationDummy() { ddx = 0.0; ddy = 0.0; }

   // Getters
   virtual double getDDX() const { assert(false); return 0.0; }
   virtual double getDDY() const { assert(false); return 0.0; }

   // Setters
   virtual void setDDX(double newDDX) { assert(false); }
   virtual void setDDY(double newDDY) { assert(false); }

   // Adds the components of otherAccel to the components of this Acceleration
   virtual void addAcceleration(const Acceleration& accel) { assert(false); };
};
