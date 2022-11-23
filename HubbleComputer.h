//
//  HubbleComputer.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/23/22.
//

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
    HubbleComputer(): HubbleComputer(Angle(0.0))
    {
        
    }
    HubbleComputer(Angle angle) : LaunchedObject(angle)
    {
        LaunchedObject* fragment1 = new Fragment(6.28319);
        LaunchedObject* fragment2 = new Fragment(2);
        launchedPieces.push_back(fragment1);
        launchedPieces.push_back(fragment2);
    }
    virtual void draw() const
    {
        drawHubbleComputer(pos, direction.getRadians());
    }
    
    virtual double getRadius() const
    {
        return 3.5;
    }
};

#endif /* HubbleComputer_h */
