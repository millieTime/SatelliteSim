/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    A single angle stored in degrees
 ************************************************************************/
#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "position.h"
long double const PI = 3.14159265358979323846;        // For vs community users

/***********************************************************
 * ANGLE
 * The angle class
 ***********************************************************/
class Angle
{
public:
   
   // Constructors
   Angle() : angle(0.0f) {};
   Angle(double angle) { setDegrees(convertToValid(angle)); }
   Angle(double x, double y) { angle =  degreesFromXY(x, y); }
   Angle(Position& p) { angle = degreesFromXY(p.getMetersX(), p.getMetersY()); }
   
   // Getters
   virtual double getDegrees() const { return angle; };
   virtual double getRadians() const { return radiansFromDegrees(angle); };
   
   // Setters
   void setDegrees(double newAngleDegrees) { angle = convertToValid(newAngleDegrees); };
   void setRadians(double newAngleRadians) { setDegrees(degreesFromRadians(newAngleRadians)); };
   
   // Updaters
   void addDegrees(double amount) { setDegrees(convertToValid(angle + amount)); };
   void addRadians(double amount) { addDegrees(degreesFromRadians(amount)); };
   
private:
   double angle;   // The angle in degrees
   
   // Converters
   double degreesFromRadians(double radians) const { return radians * 180 / PI; };
   double radiansFromDegrees(double degrees) const { return degrees * PI / 180; };
   double degreesFromXY(double x, double y)  const { return degreesFromRadians(atan2(x, y)); }
   
   // Validators
   bool verifyNewAngle(double newAngle) const { return (newAngle <= 180.0 && newAngle >= -180.0); }
   double convertToValid(double newAngle) const;
};
