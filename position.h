/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/

#pragma once

#include <iostream> 
#include <cmath>
#include "velocity.h"
#include "acceleration.h"

class TestPosition;

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend class TestPosition;
   // constructors
   Position() : x(0.0), y(0.0)  {}
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   virtual double getMetersX() const { return x;                    }
   virtual double getMetersY() const { return y;                    }
   virtual double getPixelsX() const { return x / metersFromPixels; }
   virtual double getPixelsY() const { return y / metersFromPixels; }

   // setters
   virtual void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   virtual void setMetersX(double xMeters)                { x = xMeters;              }
   virtual void setMetersY(double yMeters)                { y = yMeters;              }
   virtual void setPixelsX(double xPixels)                { x = xPixels * metersFromPixels;      }
   virtual void setPixelsY(double yPixels)                { y = yPixels * metersFromPixels;      }

   // Modifiers
   virtual void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   virtual void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   virtual void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels); }
   virtual void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels); }
   virtual void applyVelAccel(const Velocity& vel, const Acceleration& accel, double time);

   // deal with the ratio of meters to pixels
   virtual void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   virtual double getZoom() const { return metersFromPixels; }

   friend bool operator== (const Position& lhs, const Position& rhs)
   {
      return lhs.x == rhs.x && lhs.y == rhs.y;
   }

protected:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};
