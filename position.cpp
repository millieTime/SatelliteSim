/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
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
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * POINT : APPLY VELOCITY
 * Changes this position based on the given velocity and time
 * position += velocity * time
 *****************************************/
void Position::applyVelocity(const Vector2D& vel, double time)
{
   addMetersX(vel.getHorComponent() * time);
   addMetersY(vel.getVertComponent() * time);
}

/******************************************
 * POINT : APPLY VELOCITY ACCELERATION
 * Changes this position based on the given acceleration, velocity, and time
 * position += 0.5 * accel * time^2 + velocity * time
 *****************************************/
void Position::applyVelAccel(const Vector2D& accel, const Vector2D& vel, double time)
{
   // Apply the velocity
   applyVelocity(vel, time);
   // Apply the acceleration
   addMetersX(0.5 * accel.getHorComponent() * time * time);
   addMetersY(0.5 * accel.getVertComponent() * time * time);
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
