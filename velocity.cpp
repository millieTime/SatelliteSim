/***********************************************************************
 * Source File:
 *    Velocity : Represents a velocity in the orbiter simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Tracks the components of a 2-dimensional velocity, and provides
 *    a simple way to apply an acceleration over time.
 ************************************************************************/

#include "velocity.h"


/*************************************************
* VELOCITY
* The constructor for the velocity class given
* an angle and a magnitude.
**************************************************/
Velocity::Velocity(Angle& angle, double magnitude)
{
   // Calculate and set the horizontal and vertical components
   setDX(magnitude * sin(angle.getRadians()));
   setDY(magnitude * cos(angle.getRadians()));
}