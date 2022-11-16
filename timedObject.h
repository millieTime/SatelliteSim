/***********************************************************************
 * Header File:
 *    TimedObject : A Launched Object that dies after a certain amount of time.
 * Author:
 *    Preston Millward
 * Summary:
 *    Keeps track of its max lifetime and how long it has been alive.
 ************************************************************************/

#pragma once
#include "launchedObject.h"

class TimedObject : public LaunchedObject
{
public:
   TimedObject() : LaunchedObject() { secondsLeft = 0.0; }
   TimedObject(Position pos, Velocity vel) : LaunchedObject(pos, vel) { secondsLeft = 0.0; }
   virtual void advance(double seconds) { secondsLeft -= seconds; SpaceCollider::advance(seconds); };
   virtual bool isTimedOut() { return secondsLeft <= 0; }
protected:
   int secondsLeft;
};
