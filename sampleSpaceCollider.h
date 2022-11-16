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
    SampleSpaceCollider(Position& p, Velocity& v) : SpaceCollider(p, v)
    {
        
    }
    virtual void draw(const ogstream& gout)
    {
        
    }
    virtual unsigned int getRadius() const
    {
        return 1.0;
    }
};
