//
//  Hubble.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef Hubble_h
#define Hubble_h

#include "SpaceCollider.h"
#include <stdio.h>
class Hubble : public SpaceCollider
{
private:
    
public:
    Hubble(): SpaceCollider()
    {
        
    }
    Hubble(Position p, Velocity v)
    {
        this->pos = p;
        this->vel = v;
    }
    virtual void draw() const
    {
        drawHubble(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 10.0;
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
#endif /* Hubble_h */
