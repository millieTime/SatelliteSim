/***********************************************************************
 * Header File:
 *    Hubble Telescope: A part of hubble after collision
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 3 fragments.
 ************************************************************************/

#ifndef HubbleTelescope_h
#define HubbleTelescope_h

#include "launchedObject.h"
#include <stdio.h>
#include "Fragment.h"
class HubbleTelescope : public LaunchedObject
{
private:
    
public:
    // Default Constructor for Telescope
    HubbleTelescope(): HubbleTelescope(Angle(0.0))
    {
        
    }
    
    // Non-Default Constructor for Telescope
    HubbleTelescope(Angle angle) : LaunchedObject(angle)
    {
        LaunchedObject* fragment1 = new Fragment(PI / 2.0);
        LaunchedObject* fragment2 = new Fragment(2.0* PI);
        LaunchedObject* fragment3 = new Fragment(PI);
        
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
        launchedPieces.push_back(fragment3);
    }
    
    // Draw Telescope
    virtual void draw() const
    {
        drawHubbleTelescope(pos, direction.getRadians());
    }
    
    // Radius Getter for Telescope
    virtual double getRadius() const
    {
        return 5.0;
    }
};

#endif /* HubbleTelescope_h */
