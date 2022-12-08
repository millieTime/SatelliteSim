/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Gergo Medveczky and Preston Millward
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/


#pragma once

#include <cassert>
#include "acceleration.h"
#include "angleDummy.h"

using namespace std;

/******************************************************************
* MOCK CLASSES FOR THESE TEST CASES
* 
*     Angle Stub 30 : a Stub angle that points 30 degrees to the right of up
*******************************************************************/

class AngleStub30: public AngleDummy
{
public:
   AngleStub30() { angle = 0.0; }

   // Getter
   virtual double getRadians() const { return 0.5235987755982989; }
};

class TestAcceleration
{
public:

   // Runs all the test cases
   void run()
   {
      testTwoComponentConstructor();
      testMagAngleConstructor();
      testMagAngleConstructorNegativeMag();
      testAddAcceleration();
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
      Acceleration acc = Acceleration(5.0, 7.0);
      // verify
      assert(acc.ddx == 5.0);
      assert(acc.ddy == 7.0);
   }  // teardown

   void testMagAngleConstructor()
   {
      // setup
      AngleStub30 a = AngleStub30();
      // exercise
      Acceleration acc = Acceleration(a, 2.0);
      // verify
      assert(decimalCloseEnough(acc.ddx, 1.0));
      assert(decimalCloseEnough(acc.ddy, 1.7320508075688773));
   }  // teardown

   void testMagAngleConstructorNegativeMag()
   {
      // setup
      AngleStub30 a = AngleStub30();
      //exercise
      Acceleration acc = Acceleration(a, -2.0);
      //verify
      assert(decimalCloseEnough(acc.ddx, -1.0));
      assert(decimalCloseEnough(acc.ddy, -1.7320508075688773));
      // teardown
   }

   void testAddAcceleration()
   {
      // setup
      Acceleration accA = Acceleration();
      accA.ddx = 2.0;
      accA.ddy = 3.0;
      Acceleration accB = Acceleration();
      accB.ddx = -0.5;
      accB.ddy = -5.0;
      // exercise
      accA.addAcceleration(accB);
      // verify
      assert(accA.ddx == 1.5);
      assert(accA.ddy == -2.0);
   }  // teardown
};
