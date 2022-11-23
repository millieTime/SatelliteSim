/***********************************************************************
 * Header File:
 *    Fragment : A tiny piece from a piece of space junk
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Timed Object, and is launched from some satellite or satellite piece.
 ************************************************************************/

#pragma once
#include "timedObject.h"

class Fragment :public TimedObject
{
public:
   Fragment() : Fragment(Angle(0.0)) {}
   Fragment(Angle launchDirection) : TimedObject(launchDirection)
   {
      secondsLeft = random(2.0, 3.0) * TIME_DILATION;
      rotationRate = random(-PI, PI);
   }
   virtual double getRadius() const { return 2.0; };
   virtual void draw() const { drawFragment(pos, direction.getRadians()); };
};
