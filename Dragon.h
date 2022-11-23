/***********************************************************************
 * Header File:
 *    Dragon: A satellite that orbits the earth really close to the surface
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 5 pieces.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include "dragonCenter.h"
#include "dragonLeft.h"
#include "dragonRight.h"

class Dragon : public SpaceCollider
{
public:
   Dragon() : Dragon(Position(0.0, 0.0), Velocity(0.0, 0.0)) {}
   Dragon(Position p, Velocity v) : SpaceCollider(p, v)
   {
      // 3 piece, 2 frag
      LaunchedObject* center = new DragonCenter(Angle(0.0));
      LaunchedObject* frag1 = new Fragment(Angle(2.0 * PI / 5.0));
      LaunchedObject* right = new DragonRight(Angle(2.0 * 2.0 * PI / 5.0));
      LaunchedObject* left = new DragonLeft(Angle(3.0 * 2.0 * PI / 5.0));
      LaunchedObject* frag2 = new Fragment(Angle(4.0 * 2.0 * PI / 5.0));
      launchedPieces.push_back(center);
      launchedPieces.push_back(frag1);
      launchedPieces.push_back(right);
      launchedPieces.push_back(left);
      launchedPieces.push_back(frag2);
   }
   virtual void draw() const
   {
      drawCrewDragon(pos, direction.getRadians());
   }
   
   virtual double getRadius() const
   {
      return 3.5;
   }
};
