/***********************************************************************
 * Header File:
 *    Sample Space Collider : A proxy class so we can test our abstract class
 * Author:
 *    Preston Millward
 * Summary:
 *    Implements necessary functions for a Space Collider, and does nothing else.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
class SampleSpaceCollider : public SpaceCollider
{
public:
    SampleSpaceCollider() : SpaceCollider()
    {
        
    }
    SampleSpaceCollider(Position p, Velocity v) : SpaceCollider(p, v)
    {
        
    }
    void draw(const ogstream& gout)
    {
        
    }
    double getRadius()
    {
        return 0.0;
    }
};
