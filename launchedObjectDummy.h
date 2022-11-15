/***********************************************************************
 * Header File:
 *    Launched Object Dummy: A Dummy for the launched object class
 * Author:
 *    Preston Millward
 * Summary:
 *    The Launched Object class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/

#pragma once
#include "LaunchedObject.h"
#include <cassert>

class LaunchedObjectDummy : public LaunchedObject
{
public:
   LaunchedObjectDummy() : LaunchedObject() {}
   virtual void launch(Position p, Velocity v) {assert(false);}
   virtual void draw(const ogstream& gout) {}
   virtual unsigned int getRadius() const { return 0.0; }
};