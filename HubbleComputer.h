/***********************************************************************
 * Header File:
 *    Hubble Computer: A part of hubble after collision
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 2 fragments.
 ************************************************************************/

#ifndef HubbleComputer_h
#define HubbleComputer_h

#include <stdio.h>
#include "Fragment.h"
#include "launchedObject.h"
#include <stdio.h>
class HubbleComputer : public LaunchedObject
{
private:
    
public:
    // Default Constructor for computer
    HubbleComputer(): HubbleComputer(Angle(0.0))
    {
        
    }
    
    // Non-Default Constructor for computer
    HubbleComputer(Angle angle) : LaunchedObject(angle)
    {
        LaunchedObject* fragment1 = new Fragment(PI);
        LaunchedObject* fragment2 = new Fragment(2* PI);

        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
    }
    
    // Draw computer
    virtual void draw() const
    {
        drawHubbleComputer(pos, direction.getRadians());
    }
    
    // Radius Getter for Computer
    virtual double getRadius() const
    {
        return 3.5;
    }
};

#endif /* HubbleComputer_h */
