//
//  SpaceCollider.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/8/22.
//

#ifndef SpaceCollider_hpp
#define SpaceCollider_hpp
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include <list>
#include "acceleration.h"
#include <stdio.h>
#include "acceleration.h"

class TestSpaceCollider;

class SpaceCollider
{
private:
    friend class TestSpaceCollider;
    Position pos;
    Velocity vel;
    Angle direction;
    double rotationRate;
    unsigned int radius;
    list<LaunchedObject*> launchedPieces;
    
    
    
    
public:
    SpaceCollider();
    SpaceCollider(Position p, Velocity v);
    SpaceCollider(SpaceCollider &colObj);
    Position getCenter();
    double getRadius();
    bool collidesWith(SpaceCollider *otherColObj);
    protected Acceleration getGravity();
    void onCollision(list<SpaceCollider*> &collider);
    void advance(double seconds);
    virtual void draw() = 0;
    bool isTimedOut();
    
};
#endif /* SpaceCollider_h */
