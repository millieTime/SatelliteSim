/***********************************************************************
 * Header File:
 *    SpaceCollider Dummy : A dummy for the SpaceCollider class to be used in testing.
 * Author:
 *    Preston Millward
 * Summary:
 *    The SpaceCollider class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "SpaceCollider.h"
#include <cassert>

class SpaceColliderDummy : public SpaceCollider
{
   SpaceColliderDummy() {}
   virtual Position getCenter() { assert(false); return Position(); };
   virtual double getRadius() { assert(false); return 0.0; };
   virtual bool collidesWith(SpaceCollider* otherColObj) {assert(false); return false;}
};