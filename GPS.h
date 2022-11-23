/***********************************************************************
 * Header File:
 *    GPS: A satellite that orbits the earth geosynchronously
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    Is a Space Collider, and breaks into 3 pieces.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include "GPSLeft.h"
#include "GPSRight.h"
#include "GPSCenter.h"

class GPS : public SpaceCollider
{
public:
    GPS(): GPS(Position(0.0, 0.0), Velocity(0.0, 0.0)) {}
    GPS(Position p, Velocity v) : SpaceCollider(p, v)
    {
       LaunchedObject* center = new GPSCenter(Angle(0.0));
       LaunchedObject* right = new GPSRight(Angle(2.0 * PI / 3.0));
       LaunchedObject* left = new GPSLeft(Angle(2.0 * 2.0 * PI / 3.0));
       launchedPieces.push_back(center);
       launchedPieces.push_back(right);
       launchedPieces.push_back(left);
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
