//
//  SpaceCollider.cpp
//  Lab07
//
//  Created by Gergo Medveczky and Preston Millward on 11/8/22.
//

#include "SpaceCollider.h"
#include "launchedObject.h"

SpaceCollider::SpaceCollider()
{
   pos = Position(0, 0);
   vel = Velocity(0, 0);
   direction = Angle(0);
   rotationRate = 0.0;
   launchedPieces = list<LaunchedObject*>();
}

SpaceCollider::SpaceCollider(Position& p, Velocity& v)
{
   pos = p;
   vel = v;
   direction = Angle(0);
   rotationRate = 0.0;
   launchedPieces = list<LaunchedObject*>();
}

bool SpaceCollider::collidesWith(const SpaceCollider* other) const
{
   return computeDistance(pos, other->getCenter()) <= (getRadius() + other->getRadius()) * pos.getZoom();
}

void SpaceCollider::onCollision(list<SpaceCollider*>& colliders)
{
   // First, let's take ourself out of the colliders.
   list<SpaceCollider*>::iterator thisIter = find(colliders.begin(), colliders.end(), this);
   assert(thisIter != colliders.end());
   colliders.remove(this);

   // Then, let's launch all of our pieces and add them to colliders.
   for (LaunchedObject* lPtr : launchedPieces)
   {
      lPtr->launch(pos, vel);
      colliders.push_back(lPtr);
   }
}