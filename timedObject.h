/***********************************************************************
 * Header File:
 *    TimedObject : A Launched Object that dies after a certain amount of time.
 * Author:
 *    Preston Millward & Gergo Medveczky
 * Summary:
 *    Keeps track of its max lifetime and how long it has been alive.
 ************************************************************************/

#pragma once
#include "launchedObject.h"

class TimedObject : public LaunchedObject
{
public:
   // Default constructor for Timed Object
   TimedObject() : TimedObject(Angle(0.0)) {}
   // Non-default constructor for Timed object with given angle
   TimedObject(Angle launchDirection) : LaunchedObject(launchDirection) { secondsLeft = 0.0; }
   // Virtual advance function for bullet and fragment
   virtual void advance(double seconds) { secondsLeft -= seconds; SpaceCollider::advance(seconds); };
   // Virtual isdead function for fragment and bullets.
   virtual bool isDead() const { return destroyed || secondsLeft <= 0; }
protected:
   int secondsLeft;
};
