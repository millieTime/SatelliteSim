/***********************************************************************
 * Header File:
 *    GPS Left : A piece of the GPS satellite
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Launched Object, and is launched from GPS satellite
 ************************************************************************/

#pragma once
#include "launchedObject.h"
#include "Fragment.h"

class GPSCenter : public LaunchedObject
{
public:
   GPSCenter() : GPSCenter(Angle(0.0)) {}
   GPSCenter(const Angle& launchDirection) : LaunchedObject(launchDirection)
   {
      launchedPieces = list<LaunchedObject*>();
      for (int i = 0; i < 3; i++)
      {
         LaunchedObject* fragment = new Fragment(Angle(i / 3.0 * 2.0 * PI));
         launchedPieces.push_back(fragment);
      }
   }
   virtual double getRadius() const { return 3.5; };
   virtual void draw() const { drawGPSCenter(pos, direction.getRadians()); };
};