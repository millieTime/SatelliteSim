//
//  StarLink.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef StarLink_h
#define StarLink_h

#include "SpaceCollider.h"
#include <stdio.h>
class StarLink : public SpaceCollider
{
private:
    
public:
    StarLink(): SpaceCollider()
    {
        
    }
    StarLink(Position p, Velocity v)
    {
        this->pos = p;
        this->vel = v;
    }
    virtual void draw() const
    {
        drawStarlink(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 6.0;
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

#endif /* StarLink_h */
