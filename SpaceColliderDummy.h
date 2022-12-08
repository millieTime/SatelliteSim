/***********************************************************************
 * Header File:
 *    SpaceCollider Dummy : A dummy for the SpaceCollider class to be used in testing.
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    The SpaceCollider class, but all public methods (besides default constructor)
 *    contain assert(false)
 ************************************************************************/
#pragma once
#include "SpaceCollider.h"

#include <cassert>

class SpaceColliderDummy : public SpaceCollider
{
    // Default Constructor
   SpaceColliderDummy() {}
    // Dummy getter for center
   virtual Position getCenter() { assert(false); return Position(); };
    // Dummy getter for radius
   virtual double getRadius() { assert(false); return 0.0; };
    // Dummy collision with function
   virtual bool collidesWith(SpaceCollider* otherColObj) {assert(false); return false;}
};
