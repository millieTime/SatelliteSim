//
//  TestOrbitSimulator.hpp
//  Lab07
//
//  Created by Gergo Medveczky on 11/8/22.
//

#ifndef TestOrbitSimulator_h
#define TestOrbitSimulator_h
#include "sampleSpaceCollider.h"
#include "launchedObjectDummy.h"
#include "PositionDummy.h"
#include "velocityDummy.h"
#include "accelerationDummy.h"
#include <list>
#include <algorithm> // For finding items in a list
#include <cassert>

/******************************************************************
* MOCK CLASSES FOR THESE TEST CASES
*
*     Angle Stub 60 : a Stub angle that points 60 degrees to the right of up
*     Acceleration2pt5andNeg3 : a stub acceleration that represents an acceleration of (2.5, -3)
*******************************************************************/
class Position200And200 : public PositionDummy
{
public:
   Position200And200() : PositionDummy() {};
   virtual double getMetersX() const { return 200.0; }
   virtual double getMetersY() const { return 200.0; }
};

class PositionFarUp : public PositionDummy
{
public:
   PositionFarUp() : PositionDummy() {};
   virtual double getMetersX() const { return 0; }
   virtual double getMetersY() const { return EARTH_RADIUS *20; }
};

class PositionEarthRight : public PositionDummy
{
public:
   PositionEarthRight() : PositionDummy() {};
   virtual double getMetersX() const { return EARTH_RADIUS; }
   virtual double getMetersY() const { return 0.0; }
};

class PositionEarthLeft : public PositionDummy
{
public:
   PositionEarthLeft() : PositionDummy() {};
   virtual double getMetersX() const { return -EARTH_RADIUS; }
   virtual double getMetersY() const { return 0; }
};

class PositionEarthUp : public PositionDummy
{
public:
   PositionEarthUp() : PositionDummy() {};
   virtual double getMetersX() const { return 0; }
   virtual double getMetersY() const { return EARTH_RADIUS; }
};

class PositionEarthDown : public PositionDummy
{
public:
   PositionEarthDown() : PositionDummy() {};
   virtual double getMetersX() const { return 0; }
   virtual double getMetersY() const { return -EARTH_RADIUS; }
};

class VelocityNeg17pt2And25pt3 : public VelocityDummy
{
public:
    VelocityNeg17pt2And25pt3() : VelocityDummy() {};
    virtual double getDX() const { return -17.2; }
    virtual double getDY() const { return 25.3; }
};

class LaunchedObjectSpy : public LaunchedObjectDummy
{
public:
    LaunchedObjectSpy() {launchCount = 0;}
    virtual void launch(Position p, Velocity v) { launchCount++; }
    int getLaunchCount() { return launchCount; }
private:
    int launchCount;
};

class VelocitySpy : public VelocityDummy
{
public:
    VelocitySpy() {
    dx = 0;
    dy = 0;
    }
    virtual void applyAcceleration(const Acceleration& accel, double time) { velocityCount++; myTime = time; }
    int getVelocityCount() { return velocityCount; }
    double getMyTime() { return myTime; }
private:
    int velocityCount;
    double myTime;
};

class PositionSpy : public PositionDummy
{
public:
    PositionSpy() {
    x = 0;
    y = 0;
    }
    virtual void applyVelAcceleration(const Velocity& vel, const Acceleration& accel, double time) { positionCount++; myVel = vel; myTime = time; }
    int getPositionCount() { return positionCount; }
    double getMyTime() { return myTime; }
    Velocity getMyVelocity() { return myVel; }
private:
    int positionCount;
    double myTime;
    Velocity myVel;
};

/************************************
 * END MOCK CLASSES
*************************************/


class TestSpaceCollider
{
public:
    void run()
    {
        testDefaultConstructor();
        testConstructorWithPosVel();
        testgetGenter();
        testCollidesWith();
        testGetGravityUp();
        testGetGravityLeft();
        testGetGravityDown();
        testGetGravityRight();
        testGetGravityFar();
        testonCollision();
        testAdvance();
    }
    
   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

    void testDefaultConstructor()
    {
        //setup
        //exercise
        SampleSpaceCollider s;
        //verify
        assert(s.pos.getMetersX() == 0);
        assert(s.pos.getMetersY() == 0);
        //teardown
    }
    
    void testConstructorWithPosVel()
    {
        //setup
        Position200And200 p = Position200And200();
        VelocityNeg17pt2And25pt3 v = VelocityNeg17pt2And25pt3();
        //exercise
        SampleSpaceCollider s = SampleSpaceCollider(p,v);
        //verify
        assert(s.pos.getMetersX() == 200);
        assert(s.pos.getMetersX() == 200);
        assert(s.vel.getDX() == -17.2);
        assert(s.vel.getDY() == 25.3);
        //teardown
        
    }
    void testgetGenter()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = Position200And200();
        //exercise
        Position center = s.getCenter();
        //verify
        assert(center.getMetersX() == 200);
        assert(center.getMetersY() == 200);
        //teardown
    }
    
    void testCollidesWith()
    {
        //setup
        Position200And200 p = Position200And200();
        VelocityNeg17pt2And25pt3 v = VelocityNeg17pt2And25pt3();
        SampleSpaceCollider s = SampleSpaceCollider(p,v);
        SampleSpaceCollider f = SampleSpaceCollider(p,v);
        //exercise
        bool isCollided = s.collidesWith(&f);
        //verify
        
        assert(isCollided == true);
        //teardown
    }
    void testGetGravityUp()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = PositionEarthUp();
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(gravity.getDDX() == 0.0);
        assert(decimalCloseEnough(gravity.getDDY(), -9.80665));
        //teardown
    }
    void testGetGravityLeft()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = PositionEarthLeft();
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(decimalCloseEnough(gravity.getDDX(), 9.80665));
        assert(gravity.getDDY() == 0.0);
        //teardown
    }
    void testGetGravityDown()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = PositionEarthDown();
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(gravity.getDDX() == 0.0);
        assert(decimalCloseEnough(gravity.getDDY(), 9.80665));
        //teardown
    }
    void testGetGravityRight()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = PositionEarthRight();
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(decimalCloseEnough(gravity.getDDX(), -9.80665));
        assert(gravity.getDDY() == 0.0);
        //teardown
    }
    void testGetGravityFar()
    {
        //setup
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = PositionFarUp();
        //exercise
        Acceleration gravity = s.getGravity();
        //verify
        assert(gravity.getDDX() == 0.0);
        assert(decimalCloseEnough(gravity.getDDY(), -0.024516625));
        //teardown
    }

    void testonCollision()
    {
        //setup
        Position200And200 p = Position200And200();
        VelocityNeg17pt2And25pt3 v = VelocityNeg17pt2And25pt3();
        SampleSpaceCollider s = SampleSpaceCollider();
        s.pos = p;
        LaunchedObjectSpy l1 = LaunchedObjectSpy();
        LaunchedObjectSpy l2 = LaunchedObjectSpy();
        list<LaunchedObject*> piecesList = list<LaunchedObject*>();
        piecesList.push_back(&l1);
        piecesList.push_back(&l2);
        s.launchedPieces = piecesList;
        list<SpaceCollider*> colliders;
        colliders.push_back(&s);
        
        //exercise
        s.onCollision(colliders);
        
        //verify

        // s should not be in colliders anymore.
        list<SpaceCollider*>::iterator sIter = find(colliders.begin(), colliders.end(), &s);
        assert(sIter == colliders.end());

        // But the 2 launched objects should (and only those 2 objects)!
        assert(colliders.size() == 2);

        list<SpaceCollider*>::iterator l1Iter = find(colliders.begin(), colliders.end(), &l1);
        assert(l1Iter != colliders.end());

        list<SpaceCollider*>::iterator l2Iter = find(colliders.begin(), colliders.end(), &l2);
        assert(l2Iter != colliders.end());
        // And the launched objects should only be launched once.
        assert(l1.getLaunchCount() == 1);
        assert(l2.getLaunchCount() == 1);
        
        //teardown
    }

    void testAdvance()
    {
        //setup
        PositionSpy p = PositionSpy();
        VelocitySpy v = VelocitySpy();
        SampleSpaceCollider s = SampleSpaceCollider(p,v);
        double seconds = 5.0;
        //exercise
        s.advance(seconds);
        //verify
        assert(p.getPositionCount() == 1);
        assert(v.getVelocityCount() == 1);
        
        assert(v.getMyTime() == 5.0);
        assert(p.getMyTime() == 5.0);
        //teardown
    }
};
#endif /* TestOrbitSimulator_h */
