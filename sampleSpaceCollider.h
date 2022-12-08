/***********************************************************************
 * Header File:
 *    Sample Space Collider : A proxy class so we can test our abstract class
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    Implements necessary functions for a Space Collider, and does nothing else.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
class SampleSpaceCollider : public SpaceCollider
{
public:
    // Default Constructor for Sample
    SampleSpaceCollider() : SpaceCollider()
    {
        
    }
    // Non-Default Constructor for Sample
    SampleSpaceCollider(Position& p, Velocity& v) : SpaceCollider(p, v)
    {
        
    }
    // Sample draw
    virtual void draw() const
    {
        
    }
    // Sample gettradius
    virtual double getRadius() const
    {
        return 1.0;
    }
};
