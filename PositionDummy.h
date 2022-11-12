/***********************************************************************
 * Header File:
 *    Position Dummy : A dummy for the Position class to be used in testing.
 * Author:
 *    Preston Millward
 * Summary:
 *    The Position class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "position.h"
#include <cassert>

class PositionDummy : public Position
{
   PositionDummy() { x = 0.0; y = 0.0; }

   // getters
   virtual double getMetersX() const {assert(false); return 0.0; }
   virtual double getMetersY() const {assert(false); return 0.0; }
   virtual double getPixelsX() const {assert(false); return 0.0; }
   virtual double getPixelsY() const { assert(false); return 0.0; }

   // setters
   virtual void setMeters(double xMeters, double yMeters) { assert(false); }
   virtual void setMetersX(double xMeters) { assert(false); }
   virtual void setMetersY(double yMeters) { assert(false); }
   virtual void setPixelsX(double xPixels) { assert(false); }
   virtual void setPixelsY(double yPixels) { assert(false); }

   // Modifiers
   virtual void addMetersX(double dxMeters) { assert(false); }
   virtual void addMetersY(double dyMeters) { assert(false); }
   virtual void addPixelsX(double dxPixels) { assert(false); }
   virtual void addPixelsY(double dyPixels) { assert(false); }
   virtual void applyVelAccel(const Velocity& vel, const Acceleration& accel, double time) { assert(false); };

   // deal with the ratio of meters to pixels
   virtual void setZoom(double metersFromPixels){ assert(false); }
   virtual double getZoom() const { assert(false); return 0.0; }
};


