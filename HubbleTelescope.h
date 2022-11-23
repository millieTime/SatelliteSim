//
//  HubbleTelescope.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef HubbleTelescope_h
#define HubbleTelescope_h

#include "launchedObject.h"
#include <stdio.h>
#include "Fragment.h"
class HubbleTelescope : public LaunchedObject
{
private:
    
public:
    HubbleTelescope(): HubbleTelescope(Angle(0.0))
    {
        
    }
    HubbleTelescope(Angle angle)
    {
        
        direction = angle;
        
        LaunchedObject* fragment1 = new Fragment(6.28319);
        LaunchedObject* fragment2 = new Fragment(1.5708);
        LaunchedObject* fragment3 = new Fragment(4.71239);
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
        launchedPieces.push_back(fragment3);
    }
    virtual void draw() const
    {
        drawHubbleTelescope(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 10;
    }
    virtual void advance(double seconds)
    {
        SpaceCollider::advance(seconds);
    }
    virtual void onCollision(list<SpaceCollider*>& colliders)
    {
        SpaceCollider::onCollision(colliders);
    }
    virtual bool isHitBy(const SpaceCollider* otherColObj) const
    {
        return SpaceCollider::isHitBy(otherColObj);
    }
    virtual bool isDead() const { return SpaceCollider::isDead(); }
    
    
    
};

#endif /* HubbleTelescope_h */
