//
//  GPS.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef GPS_h
#define GPS_h
#include "SpaceCollider.h"
#include <stdio.h>
class GPS : public SpaceCollider
{
private:
    
public:
    GPS(): SpaceCollider()
    {
        
    }
    GPS(Position p, Velocity v)
    {
        this->pos = p;
        this->vel = v;
    }
    virtual void draw() const
    {
        drawGPS(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 6.0;
    }
};
#endif /* GPS_h */
