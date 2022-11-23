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
        return 3.0;
    }
    
    
    
    
};

#endif /* StarLink_h */
