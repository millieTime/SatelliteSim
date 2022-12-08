/***********************************************************************
 * Header File:
 *    Starlink Array : A piece of the Starlink satellite
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Launched Object, and is launched from starlink satellite
 ************************************************************************/

#pragma once
#include "launchedObject.h"
#include "Fragment.h"

class StarlinkArray : public LaunchedObject
{
public:
   StarlinkArray() : StarlinkArray(Angle(0.0)) {}
   StarlinkArray(const Angle& launchDirection) : LaunchedObject(launchDirection)
   {
      launchedPieces = list<LaunchedObject*>();
      for (int i = 0; i < 3; i++)
      {
         LaunchedObject* fragment = new Fragment(Angle(i / 3.0 * 2.0 * PI));
         launchedPieces.push_back(fragment);
      }
   }
   virtual double getRadius() const { return 2.0; };
   virtual void draw() const { drawStarlinkArray(pos, direction.getRadians()); };
};