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
        return 3.5;
    }
    
    
    
    
};


#endif /* Dragon_h */
