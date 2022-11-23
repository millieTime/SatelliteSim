//
//  Hubble.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef Hubble_h
#define Hubble_h

#include "SpaceCollider.h"
#include "HubbleTelescope.h"
#include "HubbleComputer.h"
#include "HubbleLeft.h"
#include "HubbleRight.h"
#include <stdio.h>
class Hubble : public SpaceCollider
{
private:
    
public:
    Hubble(): Hubble(Position(0,0), Velocity(0,0))
    {
    }
    Hubble(Position p, Velocity v) : SpaceCollider(p,v)
    {
        this->pos = p;
        this->vel = v;
        
        LaunchedObject* telescope = new HubbleTelescope(Angle(6.28319));
        LaunchedObject* computer = new HubbleComputer(Angle(1.5));
        LaunchedObject* leftPart = new HubbleLeft(Angle(3.141593));
        LaunchedObject* rightPart = new HubbleRight(Angle(4.9));
        
        launchedPieces.push_back(telescope);
        launchedPieces.push_back(computer);
        launchedPieces.push_back(leftPart);
        launchedPieces.push_back(rightPart);
    
    }
    virtual void draw() const
    {
        drawHubble(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 5.0;
    }
};
#endif /* Hubble_h */
