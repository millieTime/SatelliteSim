/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "test.h"       // for TEST
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "acceleration.h" // for ACCELERATION
#include "velocity.h"     // for VELOCITY
#include "constants.h"    // for various constants
using namespace std;

/*************************************************************************
 * Game
 * Plays the game of Satellite Simulator
 *************************************************************************/
class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      ptSputnik.setMetersX(0.0);
      ptSputnik.setMetersY(42164000.0);
      velSputnik = Velocity(-3100.0, 0.0);
      totalSeconds = 0;

      angleSatellite = Angle(0.0, true);
      angleEarth = Angle(0.0, true);
      phaseStar = 0;
   }

   // TODO: When checking if two things collide, make sure they both aren't dead.
   // move and rotate everything according to the amount of time that has passed.
   void advanceTime(double elapsedSeconds)
   {
      totalSeconds += elapsedSeconds;
      // rotate the earth and the satellite
      double rotationAmount = -(2 * PI / SECONDS_PER_DAY) * elapsedSeconds;
      angleEarth.addRadians(rotationAmount);
      angleSatellite.addRadians(rotationAmount);
      phaseStar++;

      // move things
      Acceleration gravity = gravityAt(ptSputnik);
      velSputnik.applyAcceleration(gravity, elapsedSeconds);
      ptSputnik.applyVelAccel(velSputnik, gravity, elapsedSeconds);
   }

   void draw(bool isSpace)
   {
      drawSputnik   (ptSputnik,    angleSatellite.getRadians());
      Position pt;
      /*
      drawHubble(ptHubble, angleSatellite);
      drawCrewDragon(ptCrewDragon, angleSatellite);
      drawStarlink  (ptStarlink,   angleSatellite);
      drawShip      (ptShip,       angleSatellite, isSpace);
      drawGPS       (ptGPS,        angleSatellite);

      // draw parts
      pt.setPixelsX(ptCrewDragon.getPixelsX() + 20);
      pt.setPixelsY(ptCrewDragon.getPixelsY() + 20);
      drawCrewDragonRight(pt, angleSatellite); // notice only two parameters are set
      pt.setPixelsX(ptHubble.getPixelsX() + 20);
      pt.setPixelsY(ptHubble.getPixelsY() + 20);
      drawHubbleLeft(pt, angleSatellite);      // notice only two parameters are set
      pt.setPixelsX(ptGPS.getPixelsX() + 20);
      pt.setPixelsY(ptGPS.getPixelsY() + 20);
      drawGPSCenter(pt, angleSatellite);       // notice only two parameters are set
      pt.setPixelsX(ptStarlink.getPixelsX() + 20);
      pt.setPixelsY(ptStarlink.getPixelsY() + 20);
      drawStarlinkArray(pt, angleSatellite);   // notice only two parameters are set

      // draw fragments
      pt.setPixelsX(ptSputnik.getPixelsX() + 20);
      pt.setPixelsY(ptSputnik.getPixelsY() + 20);
      drawFragment(pt, angleSatellite);
      pt.setPixelsX(ptShip.getPixelsX() + 20);
      pt.setPixelsY(ptShip.getPixelsY() + 20);
      drawFragment(pt, angleSatellite);

      // draw a single star
      drawStar(ptStar, phaseStar);
      */

      // draw the earth
      pt.setMeters(0.0, 0.0);
      drawEarth(pt, angleEarth.getRadians());
   }

private:
   
   // Creates the acceleration vector of gravity for a given position
   Acceleration gravityAt(Position& p)
   {
      // Get distance from point to surface of earth
      double dist = computeDistance(Position(0.0, 0.0), p);

      // Compute the force of gravity
      double gravityForce = SEA_GRAVITY * pow((EARTH_RADIUS / dist), 2);

      // Get the angle of gravity
      Angle gravityAngle = Angle(-p.getMetersX(), -p.getMetersY());

      // Return the nice package deal
      return Acceleration(gravityAngle, gravityForce);
   };




   Position ptSputnik;
   Position ptHubble;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   
   Velocity velSputnik;

   unsigned char phaseStar;
   int totalSeconds;

   Angle angleSatellite;
   Angle angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Game* pGame = (Game*)p;

   /*
   //
   // accept input
   //
   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);
   */

   //
   // perform all the game logic
   //
   
   pGame->advanceTime(TIME_DILATION / FRAME_RATE);


   //
   // draw everything
   //
   pGame->draw(pUI->isSpace());
   
}

double Position::metersFromPixels = 40.0; // What does this do? We use setZoom below. Doesn't that override it?

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();
   return 0;


   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Satellite Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Game game(ptUpperRight);

   // set everything into action
   ui.run(callBack, &game);


   return 0;
}
