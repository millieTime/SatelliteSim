/***********************************************************************
 * Header File:
 *    Starlink: A satellite that looks like a vacuum cleaner
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 2 pieces.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include "starlinkArray.h"
#include "starlinkBody.h"

class StarLink : public SpaceCollider
{
public:
    StarLink(): StarLink(Position(0.0, 0.0), Velocity(0.0, 0.0)) { }
    StarLink(Position p, Velocity v) : SpaceCollider(p, v)
    {
       LaunchedObject* SLArray = new StarlinkArray(Angle(0.0));
       LaunchedObject* SLBody = new StarlinkBody(Angle(PI));
       launchedPieces.push_back(SLArray);
       launchedPieces.push_back(SLBody);
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
