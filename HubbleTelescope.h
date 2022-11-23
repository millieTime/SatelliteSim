//
//  HubbleTelescope.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

#ifndef HubbleTelescope_h
#define HubbleTelescope_h

#include "launchedObject.h"
#include <stdio.h>
#include "Fragment.h"
class HubbleTelescope : public LaunchedObject
{
private:
    
public:
    HubbleTelescope(): HubbleTelescope(Angle(0.0))
    {
        
    }
    HubbleTelescope(Angle angle) : LaunchedObject(angle)
    {
        LaunchedObject* fragment1 = new Fragment(PI / 2.0);
        LaunchedObject* fragment2 = new Fragment(2.0* PI);
        LaunchedObject* fragment3 = new Fragment(PI);
        
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
        launchedPieces.push_back(fragment3);
    }
    virtual void draw() const
    {
        drawHubbleTelescope(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 5.0;
    }
};

#endif /* HubbleTelescope_h */
