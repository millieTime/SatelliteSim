//
//  HubbleRight.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef HubbleRight_h
#define HubbleRight_h

#include "launchedObject.h"
#include <stdio.h>
class HubbleRight : public LaunchedObject
{
private:
    
public:
    HubbleRight(): HubbleRight(Angle(0.0))
    {
        
    }
    HubbleRight(Angle angle)
    {
        direction = angle;
        LaunchedObject* fragment1 = new Fragment(6.28319);
        LaunchedObject* fragment2 = new Fragment(2);
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
    }
    virtual void draw() const
    {
        drawHubbleRight(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 8;
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



#endif /* HubbleRight_h */
