//
//  Sputnik.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/12/22.
//

#ifndef Sputnik_h
#define Sputnik_h
#include "SpaceCollider.h"
#include <stdio.h>
class Sputnik : public SpaceCollider
{
private:
    
public:
    Sputnik(): SpaceCollider()
    {
        
    }
    Sputnik(Position p, Velocity v)
    {
        this->pos = p;
        this->vel = v;
    }
    virtual void draw() const
    {
        drawSputnik(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 2.0;
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
#endif /* Sputnik_hpp */
