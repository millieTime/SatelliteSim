/***********************************************************************
 * Header File:
 *    SpaceCollider
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    An object floating in space, subject to gravity, that can hit and be hit.
 ************************************************************************/

#pragma once

#include "angle.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "uiDraw.h"
#include <cassert>
#include <list>
#include <cmath>
using namespace std;
class TestSpaceCollider;
class LaunchedObject;

class SpaceCollider
{   
public:
    // Default Constructor
   SpaceCollider() : SpaceCollider(Position(0.0, 0.0), Velocity(0.0, 0.0)) {};

    // Non-default Constructor
   SpaceCollider(const Position& p, const Velocity& v);

   // Returns the Position representing the center of this SpaceCollider.
   Position getCenter() const { return pos; };

   // Each child class will have its own radius, so there's no point having a member variable.
   virtual double getRadius() const = 0;

   // Determines if this SpaceCollider is sharing space with another SpaceCollider.
   virtual bool isHitBy(const SpaceCollider* otherColObj) const;

   // Handles the logic for when this SpaceCollider hits something. Removes this object from colliders,
   // and adds all of its LaunchedPieces to the colliders.
   virtual void onCollision(list<SpaceCollider*>& colliders);

   // Handles the logic for moving this SpaceCollider given an elapsed time.
   virtual void advance(double seconds);

   // Each child class will have its own draw function.
   virtual void draw() const = 0;

   // Whether this SpaceCollider needs to be destroyed.
   virtual bool isDead() const { return destroyed; };

   // Is this SpaceCollider the same as some other Space Collider?
   friend bool operator ==(const SpaceCollider& lhs, const SpaceCollider& rhs)
   {
      if (lhs.pos == rhs.pos && lhs.vel == rhs.vel && lhs.getRadius() == rhs.getRadius() && lhs.rotationRate == rhs.rotationRate)
      {
         return true;
      }
      return false;
   }

protected:
   friend class TestSpaceCollider;
   Position pos;
   Velocity vel;
   Angle direction;
   double rotationRate;
   bool destroyed;
   list<LaunchedObject*> launchedPieces;
   Acceleration getGravity();
};
