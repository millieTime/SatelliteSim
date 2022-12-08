/***********************************************************************
 * Header File:
 *    Starlink Body : A piece of the Starlink satellite
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Launched Object, and is launched from starlink satellite
 ************************************************************************/

#pragma once
#include "launchedObject.h"
#include "Fragment.h"

class StarlinkBody : public LaunchedObject
{
public:
   StarlinkBody() : StarlinkBody(Angle(0.0)) {}
   StarlinkBody(const Angle& launchDirection) : LaunchedObject(launchDirection)
   {
      launchedPieces = list<LaunchedObject*>();
      for (int i = 0; i < 3; i++)
      {
         LaunchedObject* fragment = new Fragment(Angle(i / 3.0 * 2.0 * PI));
         launchedPieces.push_back(fragment);
      }
   }
   virtual double getRadius() const { return 1.0; };
   virtual void draw() const { drawStarlinkBody(pos, direction.getRadians()); };
};