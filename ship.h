/***********************************************************************
 * Header File:
 *    Ship : A player-controlled ship that fires projectiles
 * Author:
 *    Preston Millward
 * Summary:
 *    Is a Space Collider, shoots Bullets, can be controlled by keyboard input.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
class Ship :  public SpaceCollider
{
public:

private:
   bool engineOn;
};

