/***********************************************************************
 * Header File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Angle. For all one functions under test =)
 ************************************************************************/

#pragma once
#include "angle.h"
#include <cassert>

using namespace std;

class TestAngle
{
public:

   // Runs all the test cases
   void run()
   {
      testConvertToValidIsValid();
      testConvertToValidZero();
      testConvertToValid2PI();
      testConvertToValidNeg2PI();
      testConvertToValidBelowNeg2PI();
      testConvertToValidAboveNeg2PI();
      testConvertToValidBelowZero();
      testConvertToValidAboveZero();
      testConvertToValidBelow2PI();
      testConvertToValidAbove2PI();
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0000000001) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   void testConvertToValidIsValid()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(2.351096547);
      // verify
      assert(decimalCloseEnough(b, 2.351096547));
   }  // teardown

   void testConvertToValidZero()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(0.0);
      // verify
      assert(decimalCloseEnough(b, 0.0));
   }  // teardown

   void testConvertToValid2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(6.28318530717958647692);
      // verify
      assert(decimalCloseEnough(b, 0.0));
   }  // teardown

   void testConvertToValidNeg2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(-6.28318530717958647692);
      // verify
      assert(decimalCloseEnough(b, 0.0));
   }  // teardown

   void testConvertToValidBelowNeg2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(-6.283186);
      // verify
      assert(decimalCloseEnough(b, 6.28318461435917295384));
   }  // teardown

   void testConvertToValidAboveNeg2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(-6.283184);
      // verify
      assert(decimalCloseEnough(b, 0.00000130717958647692));
   }  // teardown

   void testConvertToValidBelowZero()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(-0.000001);
      // verify
      assert(decimalCloseEnough(b, 6.28318430717958647692));
   }  // teardown

   void testConvertToValidAboveZero()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(0.000001);
      // verify
      assert(decimalCloseEnough(b, 0.000001));
   }  // teardown

   void testConvertToValidBelow2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(6.283184);
      // verify
      assert(decimalCloseEnough(b, 6.283184));
   }  // teardown

   void testConvertToValidAbove2PI()
   {
      // setup
      Angle a = Angle();
      // exercise
      double b = a.convertToValid(6.283186);
      // verify
      assert(decimalCloseEnough(b, 0.00000069282041352307));
   }  // teardown
};