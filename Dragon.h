//
//  Dragon.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef Dragon_h
#define Dragon_h

#include "SpaceCollider.h"
#include <stdio.h>
class Dragon : public SpaceCollider
{
private:
    
public:
    Dragon(): SpaceCollider()
    {
        
    }
    Dragon(Position p, Velocity v)
    {
        this->pos = p;
        this->vel = v;
    }
    virtual void draw() const
    {
        drawCrewDragon(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 7.0;
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


#endif /* Dragon_h */
