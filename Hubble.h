/***********************************************************************
 * Header File:
 *    Hubble: A satellite that orbits the earth geosynchronously
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 4 parts.
 ************************************************************************/

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
    // Default Constructor for Hubble
    Hubble(): Hubble(Position(0,0), Velocity(0,0))
    {
    }
    
    // Non-Default Constructor for Hubble
    Hubble(Position p, Velocity v) : SpaceCollider(p,v)
    {
        LaunchedObject* telescope = new HubbleTelescope(Angle(PI / 2.0 ));
        LaunchedObject* computer = new HubbleComputer(Angle(PI));
        LaunchedObject* leftPart = new HubbleLeft(Angle((PI * 2.0)/3.0));
        LaunchedObject* rightPart = new HubbleRight(Angle(2.0* PI));
        
        launchedPieces.push_back(telescope);
        launchedPieces.push_back(computer);
        launchedPieces.push_back(leftPart);
        launchedPieces.push_back(rightPart);
    
    }
    
    // Draw Hubble
    virtual void draw() const
    {
        drawHubble(pos, direction.getRadians());
    }
    
    // Radius getter for Hubble
    virtual double getRadius() const
    {
        return 5.0;
    }
};
#endif /* Hubble_h */
