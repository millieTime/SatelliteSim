/***********************************************************************
 * Header File:
 *    Hubble Left-Part: A part of hubble after collision
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 2 fragments.
 ************************************************************************/

#ifndef HubbleLeft_h
#define HubbleLeft_h

#include "launchedObject.h"
#include <stdio.h>
class HubbleLeft : public LaunchedObject
{
private:
    
public:
    // Default Constructor for HubbleLeft
    HubbleLeft(): HubbleLeft(Angle(0.0))
    {
        
    }
    
    // Non-Default Constructor for HubbleLeft
    HubbleLeft(const Angle& angle) : LaunchedObject(angle)
    {
        LaunchedObject* fragment1 = new Fragment(6.28319);
        LaunchedObject* fragment2 = new Fragment(2);
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
    }
    
    // Draw HubbleLeft
    virtual void draw() const
    {
        drawHubbleLeft(pos, direction.getRadians());
    }
    
    // Radius Getter for HubbleLeft
    virtual double getRadius() const
    {
        return 4.0;
    }
    
    
};

#endif /* HubbleLeft_h */
