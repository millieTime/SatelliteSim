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
 * valid angle. [0, 360)
 **************************************************/
double Angle :: convertToValid(double newAngle) const
{
   // if the angle is greater than 180
   while (newAngle >= 360.0)
      // subtract 360 to get the same direction but in the valid range
      newAngle = newAngle - 360.0;

   // if the angle is less than 180
   while (newAngle < 0)
      // add 360 to get the same direction but in the valid range
      newAngle = newAngle + 360.0;

   return newAngle;
};
