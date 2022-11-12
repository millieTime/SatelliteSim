/***********************************************************************
 * Header File:
 *    Launched Object : Represents an expelled SpaceCollider in the orbiter simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Provides a way to easily launch this piece of space debris.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"

class LaunchedObject : public SpaceCollider
{
public:
   LaunchedObject() : SpaceCollider() {}
   LaunchedObject(Position p, Velocity v) : SpaceCollider(p, v) {}
   virtual void launch(Position p, Velocity v) = 0;
};