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
# include "Fragment.h"
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
        LaunchedObject* fragment1 = new Fragment(PI / 2.0 );
        LaunchedObject* fragment2 = new Fragment(PI);
        LaunchedObject* fragment3 = new Fragment((PI * 2.0)/3.0);
        LaunchedObject* fragment4 = new Fragment(2.0* PI);
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
        launchedPieces.push_back(fragment3);
        launchedPieces.push_back(fragment4);
    }
    virtual void draw() const
    {
        drawSputnik(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 2.0;
    }
    
    
    
    
};
#endif /* Sputnik_hpp */
