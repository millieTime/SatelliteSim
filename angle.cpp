/***************************************************************************************
 * Header File:
 *    Angle : Represents an angle in the satellite simulation
 *    where 0 radians is up.
 * Author:
 *    Preston Millward
 * Summary:
 *    Keeps track of an angle in radians.
 ***************************************************************************************/

#include "angle.h"     // for the angle class definition
#include <cassert>

/*************************************************
 * CONVERT TO VALID
 * A method to convert an invalid angle to a
 * valid angle. approximately [0, 2*PI)
 **************************************************/
double Angle :: convertToValid(double newAngle) const
{
   // Figure out how many 2*PI's we need to subtract, and do it.
   int multiplyer = floor(newAngle / (2.0 * PI));
   newAngle -= multiplyer * 2.0 * PI;

   return newAngle;
};
