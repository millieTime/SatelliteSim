/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the satellite simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    A single angle stored in radians
 ************************************************************************/
#pragma once
#include <cmath>
#include "constants.h"

class TestAngle;

/***********************************************************
 * ANGLE
 * The angle class. Tracks an angle measured in radians.
 ***********************************************************/
class Angle
{
public:
   friend class TestAngle;

   // Constructors
   Angle() : angle(0.0f) {}
   Angle(double angle)
   {
      setRadians(angle);
   }
   Angle(double x, double y) { setRadians(radiansFromXY(x, y)); }
   
   // Getter
   virtual double getRadians() const { return angle; }
   
   // Setter
   virtual void setRadians(double newAngleRadians) { angle = convertToValid(newAngleRadians); };
   
   // Updater
   virtual void addRadians(double amount) { setRadians(angle + amount); };
   
protected:
   double angle;   // The angle in radians
   
   // Converters
   double radiansFromXY(double x, double y) const  { return atan2(x, y); }
   
   // Validators
   double convertToValid(double newAngle) const;
};
