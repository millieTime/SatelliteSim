/***********************************************************************
 * Header File:
 *    Dragon Center : A piece of the Crew Dragon satellite
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Launched Object, and is launched from Crew Dragon satellite
 ************************************************************************/

#pragma once
#include "launchedObject.h"
#include "Fragment.h"

class DragonCenter : public LaunchedObject
{
public:
   DragonCenter() : DragonCenter(Angle(0.0)) {}
   DragonCenter(const Angle& launchDirection) : LaunchedObject(launchDirection)
   {
      launchedPieces = list<LaunchedObject*>();
      for (int i = 0; i < 4; i++)
      {
         LaunchedObject* fragment = new Fragment(Angle(i / 4.0 * 2.0 * PI));
         launchedPieces.push_back(fragment);
      }
   }
   virtual double getRadius() const { return 3.0; };
   virtual void draw() const { drawCrewDragonCenter(pos, direction.getRadians()); };
};