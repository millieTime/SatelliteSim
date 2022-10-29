/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    A single angle stored in radians
 ************************************************************************/
#pragma once
#include <cmath>
#include "constants.h"

/***********************************************************
 * ANGLE
 * The angle class
 ***********************************************************/
class Angle
{
public:
   
   // Constructors
   Angle() : angle(0.0f) {}
   Angle(double angle, bool isRadians)
   {
      if (isRadians)
         setRadians(angle);
      else
         setDegrees(angle);
   }
   Angle(double x, double y) { setRadians(radiansFromXY(x, y)); }
   
   // Getters
   double getDegrees() const { return degreesFromRadians(angle); }
   double getRadians() const { return angle; }
   
   // Setters
   void setDegrees(double newAngleDegrees) { setRadians(radiansFromDegrees(newAngleDegrees)); };
   void setRadians(double newAngleRadians) { angle = convertToValid(newAngleRadians); };
   
   // Updaters
   void addDegrees(double amount) { addRadians(radiansFromDegrees(amount)); };
   void addRadians(double amount) { setRadians(angle + amount); };
   
private:
   double angle;   // The angle in radians
   
   // Converters
   double degreesFromRadians(double radians) const { return radians * 180 / PI; };
   double radiansFromDegrees(double degrees) const { return degrees * PI / 180; };
   double radiansFromXY(double x, double y) const  { return atan2(x, y); }
   
   // Validators
   bool verifyNewAngle(double newAngle) const { return (newAngle <= PI && newAngle >= 0.0); }
   double convertToValid(double newAngle) const;
};
