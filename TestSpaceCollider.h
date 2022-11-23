//
//  TestOrbitSimulator.h
//  Lab07
//
//  Created by Gergo Medveczky and Preston Millward on 11/8/22.
//

#pragma once
#include "sampleSpaceCollider.h"
#include "launchedObjectDummy.h"
#include "PositionDummy.h"
#include "velocityDummy.h"
#include "angleDummy.h"
#include "accelerationDummy.h"
#include <list>
#include <algorithm> // For finding items in a list
#include <cassert>

/******************************************************************
* MOCK CLASSES FOR THESE TEST CASES
*
*     Position 200 and 200     : a Stub Position at (200, 200)
*     PositionFarUp            : a Stub Position at 20 times the earth's radius straight up
*     PositionEarthRight       : a Stub Position on the earth's surface straight Right
*     PositionEarthLeft        : a Stub Position on the earth's surface straight Left
*     PositionEarthUp          : a Stub Position on the earth's surface straight Up
*     PositionEarthDown        : a Stub Position on the earth's surface straight Down
*     VelocityNeg17pt2And25pt3 : a Stub Velocity of (-17.2, 25.3)
*     VelocityZeroAndZero      : a Stub Velocity of (0, 0)
*     LaunchedObjectSpy        : a Spy LaunchedObject that tracks how many times it was launched()
*                                and with what position and velocity it was launched.
*     VelocitySpy              : a Spy Velocity that tracks how many times applyAcceleration was called
*                                and with what time it was applied.
*     PositionSpy              : a Spy Position that tracks how many times applyVelAccel was called
*                                and with what time it was applied.
*     Angle2                   : a Stub Angle representing 2 radians.
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
   virtual double getMetersY() const { return 127560000.0; }
};

class PositionEarthRight : public PositionDummy
{
public:
   PositionEarthRight() : PositionDummy() {};
   virtual double getMetersX() const { return 6378000.0; }
   virtual double getMetersY() const { return 0.0; }
};

class PositionEarthLeft : public PositionDummy
{
public:
   PositionEarthLeft() : PositionDummy() {};
   virtual double getMetersX() const { return -6378000.0; }
   virtual double getMetersY() const { return 0; }
};

class PositionEarthUp : public PositionDummy
{
public:
   PositionEarthUp() : PositionDummy() {};
   virtual double getMetersX() const { return 0; }
   virtual double getMetersY() const { return 6378000.0; }
};

class PositionEarthDown : public PositionDummy
{
public:
   PositionEarthDown() : PositionDummy() {};
   virtual double getMetersX() const { return 0; }
   virtual double getMetersY() const { return -6378000.0; }
};

class VelocityNeg17pt2And25pt3 : public VelocityDummy
{
public:
   VelocityNeg17pt2And25pt3() : VelocityDummy() {};
   virtual double getDX() const { return -17.2; }
   virtual double getDY() const { return 25.3; }
};

class VelocityZeroAndZero : public VelocityDummy
{
public:
   VelocityZeroAndZero() : VelocityDummy() {};
   virtual double getDX() const { return 0.0; }
   virtual double getDY() const { return 0.0; }
};

class LaunchedObjectSpy : public LaunchedObjectDummy
{
public:
   LaunchedObjectSpy() { launchCount = 0; myPosition = Position(); myVelocity = Velocity(); }
   virtual void launch(const Position& p, const Velocity& v) { launchCount++; }
   int getLaunchCount() { return launchCount; }
   Position getLaunchPosition() { return myPosition; }
   Velocity getLaunchVelocity() { return myVelocity; }

private:
   int launchCount;
   Position myPosition;
   Velocity myVelocity;
};

class VelocitySpy : public VelocityDummy
{
public:
   VelocitySpy()
   {
   dx = 0;
   dy = 0;
   velocityCount = 0;
   myTime = 0.0;
   }
   virtual double getDX() const { return 0.0; }
   virtual double getDY() const { return 0.0; }
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
   PositionSpy()
   {
   x = 0;
   y = 0;
   positionCount = 0;
   myTime = 0.0;
   myVel = Velocity();
   }
   virtual double getMetersX() const { return 0.0; }
   virtual double getMetersY() const { return 0.0; }
   virtual void applyVelAcceleration(const Velocity& vel, const Acceleration& accel, double time) { positionCount++; myVel = vel; myTime = time; }
   int getPositionCount() { return positionCount; }
   double getMyTime() { return myTime; }
   Velocity getMyVelocity() { return myVel; }
private:
   int positionCount;
   double myTime;
   Velocity myVel;
};

class Angle2 : public AngleDummy
{
public:
   Angle2() { angle = 2.0; }
   virtual double getRadians() const { return 2.0; }
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
      testIsHitByTrue();
      testIsHitByFalse();
      testonCollision();
      testgetGenter();
      testGetGravityUp();
      testGetGravityLeft();
      testGetGravityDown();
      testGetGravityRight();
      testGetGravityFar();
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
    
   void testIsHitByTrue()
   {
      //setup
      Position200And200 p = Position200And200();
      VelocityNeg17pt2And25pt3 v = VelocityNeg17pt2And25pt3();
      SampleSpaceCollider s = SampleSpaceCollider(p,v);
      SampleSpaceCollider f = SampleSpaceCollider(p,v);
      //exercise
      bool isCollided = s.isHitBy(&f);
      //verify
        
      assert(isCollided == true);
      //teardown
   }

   void testIsHitByFalse()
   {
      // setup
      PositionEarthUp up = PositionEarthUp();
      PositionEarthDown down = PositionEarthDown();
      VelocityZeroAndZero v = VelocityZeroAndZero();
      SampleSpaceCollider s1 = SampleSpaceCollider();
      s1.pos = up;
      s1.vel = v;
      SampleSpaceCollider s2 = SampleSpaceCollider();
      s2.pos = down;
      s2.vel = v;

      // exercise
      bool doesCollide = s1.isHitBy(&s2);

      // verify
      assert(!doesCollide);

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
      assert(decimalCloseEnough(gravity.getDDX(), 0.0));
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
      assert(decimalCloseEnough(gravity.getDDY(), 0.0));
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
      assert(decimalCloseEnough(gravity.getDDX(), 0.0));
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
      assert(decimalCloseEnough(gravity.getDDY(), 0.0));
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
      assert(decimalCloseEnough(gravity.getDDX(), 0.0));
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

      // s should be marked as dead
      assert(s.destroyed == true);

      // And the 2 launched objects should be in the list with their parent!
      assert(colliders.size() == 3);

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
      PositionEarthUp p = PositionEarthUp();
      VelocityNeg17pt2And25pt3 v = VelocityNeg17pt2And25pt3();
      Angle2 a = Angle2();
      SampleSpaceCollider s = SampleSpaceCollider();
      s.pos = p;
      s.vel = v;
      s.rotationRate = -0.1;
      s.direction = a;
      double seconds = 5.0;
      //exercise
      s.advance(seconds);
      //verify
      assert(decimalCloseEnough(s.pos.getMetersX(), -86.0));
      assert(decimalCloseEnough(s.pos.getMetersY(), 6377758.750625));
      assert(decimalCloseEnough(s.vel.getDX(), -17.2));
      assert(decimalCloseEnough(s.vel.getDY(), -23.73325));
      assert(decimalCloseEnough(s.direction.getRadians(), 1.5));
      //teardown
   }
};
