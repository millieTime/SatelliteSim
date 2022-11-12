//
//  SpaceCollider.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/8/22.
//

#ifndef SpaceCollider_h
#define SpaceCollider_h
#include "angle.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "uiDraw.h"
#include <list>
using namespace std;
class TestSpaceCollider;
class LaunchedObject;
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
    
protected:
   Acceleration getGravity() { return Acceleration(); };
    
    
public:
   SpaceCollider() {};
   SpaceCollider(Position p, Velocity v) {};
   Position getCenter() { return Position(); };
    virtual double getRadius() = 0;
    bool collidesWith(SpaceCollider* otherColObj) { return false; };
    void onCollision(list<SpaceCollider*>& collider) {};
    void advance(double seconds) {};
    virtual void draw(const ogstream& gout) = 0;
    bool isTimedOut() { return false; };
    friend bool operator ==(const SpaceCollider& lhs, const SpaceCollider& rhs)
    {
        if (lhs.pos == rhs.pos && lhs.vel == rhs.vel && lhs.radius == rhs.radius && lhs.rotationRate == rhs.rotationRate)
        {
            return true;
        }
        return false;
    }
};
#endif /* SpaceCollider_h */
