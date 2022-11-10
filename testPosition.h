/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "accelerationDummy.h"
#include "velocityDummy.h"
#include <cassert>

using namespace std;

/******************************************************************
* MOCK CLASSES FOR THESE TEST CASES
*
*     AccelerationZero     : a stub acceleration that represents zero acceleration.
*     Acceleration2pt5and3 : a stub acceleration that represents an acceleration of (2.5, 3)
*     VelocityZero         : a stub velocity that represents zero velocity
*     VelocityNeg2and3pt5  : a stub velocity that represents velocity of (-2, 3.5)
*******************************************************************/
class AccelerationZero : public AccelerationDummy
{
public:
   AccelerationZero() : AccelerationDummy() {};
   virtual double getDDX() const { return 0.0; }
   virtual double getDDY() const { return 0.0; }
};

class Acceleration2pt5and3 : public AccelerationDummy
{
public:
   Acceleration2pt5and3() : AccelerationDummy() {};
   virtual double getDDX() const { return 2.5; }
   virtual double getDDY() const { return 3.0; }
};

class VelocityZero : public VelocityDummy
{
public:
   VelocityZero() : VelocityDummy() {};
   virtual double getDX() const { return 0.0; }
   virtual double getDY() const { return 0.0; }
};

class VelocityNeg2and3pt5 : public VelocityDummy
{
public:
   VelocityNeg2and3pt5() : VelocityDummy() {};
   virtual double getDX() const { return -2.0; }
   virtual double getDY() const { return 3.5; }
};


/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition
{
public:
   void run()
   {
      Position().setZoom(1000.0 /* 1km equals 1 pixel */);
      defaultConstructor();
      nonDefaultConstructor();
      copyConstructor();
      assignment();
 
      setPixels();
      setMeters();
      
      addPixels();
      addMeters();

      applyNoVelocityNoAccel();
      applyVelocityNoAccel();
      applyAccelNoVelocity();
      applyVelocityAccel();
   }
   
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void defaultConstructor() const
   {  // setup
      // exercise
      Position pos;
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown

   void nonDefaultConstructor() const
   {  // setup
      // exercise
      Position pos(3000.0, 9000.0);
      // verify
      assert(pos.x == 3000.0);
      assert(pos.y == 9000.0);
   }  // teardown

   void copyConstructor() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2(pos1);
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown

   void assignment() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2 = pos1;
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown
   
   void setMeters() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setMetersX(5000.0);
      pos.setMetersY(3000.0);
      // verify
      assert(pos.x == 5000.0);
      assert(pos.y == 3000.0);
   }  // teardown
 
   void setPixels() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setPixelsX(6.0);
      pos.setPixelsY(12.0);
      // verify
      assert(pos.x == 6000.0);
      assert(pos.y == 12000.0);
   }  // teardown
   
   void addMeters() const
   {  // setup
      Position pos;
      pos.x = 800.0;
      pos.y = 1600.0;
      // exercise
      pos.addMetersX(-400.0);
      pos.addMetersY(800.0);
      // verify
      assert(pos.x == 400.0);
      assert(pos.y == 2400.0);
   }  // teardown
   
   void addPixels() const
   {  // setup
      Position pos;
      pos.x = 2000.0;
      pos.y = 4000.0;
      // exercise
      pos.addPixelsX(2);
      pos.addPixelsY(3);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 7000.0);
   }  // teardown

   void applyNoVelocityNoAccel() const
   {
      // setup
      AccelerationZero a = AccelerationZero();
      VelocityZero v = VelocityZero();
      Position p = Position();
      p.x = 7.0;
      p.y = 4.0;
      // exercise
      p.applyVelAccel(v, a, 2.0);
      // verify
      assert(p.x == 7.0);
      assert(p.y == 4.0);
      // teardown
   }
   void applyVelocityNoAccel() const
   {
      // setup
      AccelerationZero a = AccelerationZero();
      VelocityNeg2and3pt5 v = VelocityNeg2and3pt5();
      Position p = Position();
      p.x = 7.0;
      p.y = 4.0;
      // exercise
      p.applyVelAccel(v, a, 2.0);
      // verify
      assert(p.x == 3.0);
      assert(p.y == 11.0);
      // teardown
   }
   void applyAccelNoVelocity() const
   {
      // setup
      Acceleration2pt5and3 a = Acceleration2pt5and3();
      VelocityZero v = VelocityZero();
      Position p = Position();
      p.x = 7.0;
      p.y = 4.0;
      // exercise
      p.applyVelAccel(v, a, 2.0);
      // verify
      assert(p.x == 12.0);
      assert(p.y == 10.0);
      // teardown
   }
   void applyVelocityAccel() const
   {
      // setup
      Acceleration2pt5and3 a = Acceleration2pt5and3();
      VelocityNeg2and3pt5 v = VelocityNeg2and3pt5();
      Position p = Position();
      p.x = 7.0;
      p.y = 4.0;
      // exercise
      p.applyVelAccel(v, a, 2.0);
      // verify
      assert(p.x == 8.0);
      assert(p.y == 17.0);
      // teardown
   }

};
