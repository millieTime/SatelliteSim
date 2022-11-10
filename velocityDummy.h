/***********************************************************************
 * Header File:
 *    Velocity Dummy : A dummy for the velocity class to be used in testing.
 * Author:
 *    Preston Millward
 * Summary:
 *    The velocity class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "velocity.h"
#include <cassert>

class VelocityDummy : public Velocity
{
public:

   // Default constructor
   VelocityDummy() { dx = 0.0; dy = 0.0; }

   // Getters
   virtual double getDX() const { assert(false); return 0.0; }
   virtual double getDY() const { assert(false); return 0.0; }

   // Setters
   virtual void setDX(double newDX) { assert(false); }
   virtual void setDY(double newDY) { assert(false); }

   // Apply an acceleration to this velocity for the specified amount of time
   virtual void applyAcceleration(const Acceleration& accel, double time) { assert(false); }
};
