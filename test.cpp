/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich & Preston Millward
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testAngle.h"
#include "testPosition.h"
#include "testAcceleration.h"
#include "testVelocity.h"
#include "TestSpaceCollider.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestAngle().run();
   TestPosition().run();
   TestVelocity().run();
   TestAcceleration().run();
   TestSpaceCollider().run();
}
