/***************************************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 *    where 0 degrees is up.
 * Author:
 *    Emilio Regino & Preston Millward
 * Summary:
 *    Keeps track of an angle, and provides an easy interface to convert to
 *    and from degrees and radians
 ***************************************************************************************/

#include "angle.h"     // for the angle class definition

/*************************************************
 * CONVERT TO VALID
 * A method to convert an invalid angle to a
 * valid angle. approximately [0, 2*PI)
 **************************************************/
double Angle :: convertToValid(double newAngle) const
{
   // if the angle is greater than 2 * PI
   while (newAngle >= 2 * PI)
      // subtract 2 * PI to get the same direction but in the valid range
      newAngle -= 2 * PI;

   // if the angle is less than 0
   while (newAngle < 0)
      // add 2 * PI to get the same direction but in the valid range
      newAngle = newAngle + 2 * PI;

   return newAngle;
};