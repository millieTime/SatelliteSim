/***********************************************************************
 * Header File:
 *    Angle Dummy : A dummy for the angle class to be used in testing.
 * Author:
 *    Preston Millward
 * Summary:
 *    The angle class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "angle.h"
#include <cassert>

class AngleDummy : public Angle
{
public:
   AngleDummy() { angle = 0.0; }

   // Getter
   virtual double getRadians() const { assert(false); return 0.0; }

   // Setter
   virtual void setRadians(double newAngleRadians) {assert(false); };

   // Updater
   virtual void addRadians(double amount) { assert(false); };
};

