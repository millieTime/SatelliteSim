/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich, Preston Millward, and Gergo Medveczky
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.getMetersX();
   y = pt.getMetersY();
   return *this;
}

/******************************************
 * POINT : APPLY VELOCITY ACCELERATION
 * Changes this position based on the given acceleration, velocity, and time
 * position += 0.5 * accel * time^2 + velocity * time
 *****************************************/
void Position::applyVelAccel(const Velocity& vel, const Acceleration& accel, double time)
{
   addMetersX(vel.getDX() * time + 0.5 * accel.getDDX() * time * time);
   addMetersY(vel.getDY() * time + 0.5 * accel.getDDY() * time * time);
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}
