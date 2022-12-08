/***********************************************************************
 * Source File:
 *    SpaceCollider
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    An object floating in space, subject to gravity, that can hit and be hit.
 ************************************************************************/

#include "SpaceCollider.h"
#include "launchedObject.h"

//Non-default Constructor for Space collider
SpaceCollider::SpaceCollider(const Position& p, const Velocity& v)
{
   pos = p;
   vel = v;
   direction = Angle(0);
   rotationRate = 0.0;
   launchedPieces = list<LaunchedObject*>();
   destroyed = false;
}

/*********************************************
* SPACE COLLIDER : IS HIT BY
*    Determines whether this Space Collider intersects
*    with another Space Collider.
*    Compares the distance between the two to the sum
*    of their radii.
**********************************************/
bool SpaceCollider::isHitBy(const SpaceCollider* other) const
{
   return computeDistance(pos, other->getCenter()) <= (getRadius() + other->getRadius()) * pos.getZoom();
}

/*********************************************
* SPACE COLLIDER : ON COLLISION
*    Handles what happens when this Space Collider
*    is destroyed. Namely, marks it as destroyed
*    and adds any broken pieces to the list of colliders.
**********************************************/
void SpaceCollider::onCollision(list<SpaceCollider*>& colliders)
{
   // Mark ourself dead
   destroyed = true;

   // Then, let's launch all of our pieces and add them to colliders.
   for (LaunchedObject* lPtr : launchedPieces)
   {
      lPtr->launch(pos, vel);
      colliders.push_front(lPtr);
   }
}

/*********************************************
* SPACE COLLIDER : GET GRAVITY
*    Determines the acceleration due to gravity
*    applied to this space collider.
**********************************************/
Acceleration SpaceCollider::getGravity()
{
   // Get distance from point to surface of earth
   double dist = computeDistance(Position(0.0, 0.0), pos);

   // Compute the force of gravity
   double gravityForce = SEA_GRAVITY * pow((EARTH_RADIUS / dist), 2);

   // Get the angle of gravity
   Angle gravityAngle = Angle(-pos.getMetersX(), -pos.getMetersY());

   // Return the nice package deal
   return Acceleration(gravityAngle, gravityForce);
}


/*********************************************
* SPACE COLLIDER : ADVANCE
*    Handles the logic for moving and rotating
*    this SpaceCollider given an elapsed time.
*    Uses vt = v0 + a*t and pt = p0 + v*t + .5*a*t*t
**********************************************/
void SpaceCollider::advance(double seconds)
{
   // To add accuracy, calculate two movements instead of one.
   // This first part will undershoot a bit.
   Acceleration gravity = getGravity();
   vel.applyAcceleration(gravity, seconds / 2.0);
   pos.applyVelAccel(vel, gravity, seconds / 2.0);

   // And this second part overshoots a bit.
   gravity = getGravity();
   pos.applyVelAccel(vel, gravity, seconds / 2.0);
   vel.applyAcceleration(gravity, seconds / 2.0);

   // Spin
   direction.addRadians(rotationRate * seconds);
}
