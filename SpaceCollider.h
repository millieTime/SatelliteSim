//
//  SpaceCollider.hpp
//  Lab07
//
//  Created by Gergo Medveczky and Preston Millward on 11/8/22.
//

#ifndef SpaceCollider_h
#define SpaceCollider_h
#include "angle.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "uiDraw.h"
#include <cassert>
#include <list>
using namespace std;
class TestSpaceCollider;
class LaunchedObject;

class SpaceCollider
{
protected:
   friend class TestSpaceCollider;
   Position pos;
   Velocity vel;
   Angle direction;
   double rotationRate;
   list<LaunchedObject*> launchedPieces;
   Acceleration getGravity() { return Acceleration(); };
    
public:
   SpaceCollider();
   SpaceCollider(Position& p, Velocity& v);

   // Returns the Position representing the center of this SpaceCollider.
   Position getCenter() const { return pos; };

   // Each child class will have its own radius, so there's no point having a member variable.
   virtual unsigned int getRadius() const = 0;

   // Determines if this SpaceCollider is sharing space with another SpaceCollider.
   // Calculates the distance between the two centers, and compares it to the sum of radii.
   bool collidesWith(const SpaceCollider* otherColObj) const;

   // Handles the logic for when this SpaceCollider hits something. Removes this object from colliders,
   // and adds all of its LaunchedPieces to the colliders.
   void onCollision(list<SpaceCollider*>& colliders);

   // Handles the logic for moving this SpaceCollider given an elapsed time.
   void advance(double seconds) {};

   // Each child class will have its own draw function.
   virtual void draw(const ogstream& gout) = 0;

   // Whether this SpaceCollider is out of time. Only used by child classes that time out.
   bool isTimedOut() { return false; };

   // Is this SpaceCollider the same as some other Space Collider?
   friend bool operator ==(const SpaceCollider& lhs, const SpaceCollider& rhs)
   {
      if (lhs.pos == rhs.pos && lhs.vel == rhs.vel && lhs.getRadius() == rhs.getRadius() && lhs.rotationRate == rhs.rotationRate)
      {
         return true;
      }
      return false;
   }
};
#endif /* SpaceCollider_h */
