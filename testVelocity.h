/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/


#pragma once

#include <cassert>
#include "velocity.h"
#include "accelerationDummy.h"
#include "angleDummy.h"

using namespace std;

/******************************************************************
* MOCK CLASSES FOR THESE TEST CASES
*
*     Angle Stub 60 : a Stub angle that points 60 degrees to the right of up
*     Acceleration2pt5andNeg3 : a stub acceleration that represents an acceleration of (2.5, -3)
*******************************************************************/

class AngleStub60 : public AngleDummy
{
public:
   AngleStub60() { angle = 0.0; }

   // Getter
   virtual double getRadians() const { return 1.0471975511965977; }
};
class Acceleration2pt5andNeg3 : public AccelerationDummy
{
public:
   Acceleration2pt5andNeg3() : AccelerationDummy() {};
   virtual double getDDX() const { return 2.5; }
   virtual double getDDY() const { return -3.0; }
};

class TestVelocity
{
public:

   // Runs all the test cases
   void run()
   {
      testTwoComponentConstructor();
      testMagAngleConstructor();
      testApplyAcceleration();
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   void testTwoComponentConstructor()
   {
      // setup
      // exercise
      Velocity vel = Velocity(5.0, 7.0);
      // verify
      assert(vel.dx == 5.0);
      assert(vel.dy == 7.0);
   }  // teardown

   void testMagAngleConstructor()
   {
      // setup
      AngleStub60 a = AngleStub60();
      // exercise
      Velocity vel = Velocity(a, 2.0);
      // verify
      assert(decimalCloseEnough(vel.dx, 1.7320508075688773));
      assert(decimalCloseEnough(vel.dy, 1.0));
   }  // teardown

   void testApplyAcceleration()
   {
      // setup
      Velocity vel = Velocity();
      vel.dx = -23.0;
      vel.dy = 4.5;
      Acceleration2pt5andNeg3 a = Acceleration2pt5andNeg3();
      // exercise
      vel.applyAcceleration(a, 3.0);
      // verify
      assert(vel.dx == -15.5);
      assert(vel.dy == -4.5);
   }  // teardown
};