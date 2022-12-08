/***********************************************************************
 * Header File:
 *    Dragon Left: A piece of the Crew Dragon satellite
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Launched Object, and is launched from Crew Dragon satellite
 ************************************************************************/

#pragma once
#include "launchedObject.h"
#include "Fragment.h"

class DragonLeft : public LaunchedObject
{
public:
   DragonLeft() : DragonLeft(Angle(0.0)) {}
   DragonLeft(const Angle& launchDirection) : LaunchedObject(launchDirection)
   {
      launchedPieces = list<LaunchedObject*>();
      for (int i = 0; i < 2; i++)
      {
         LaunchedObject* fragment = new Fragment(Angle(i / 2.0 * 2.0 * PI));
         launchedPieces.push_back(fragment);
      }
   }
   virtual double getRadius() const { return 3.0; };
   virtual void draw() const { drawCrewDragonLeft(pos, direction.getRadians()); };
};