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
#include "SpaceCollider.h" // for all the space junk 
#include "ship.h"          // da ship
#include "Sputnik.h"        // Sputnik
#include "GPS.h"               //GPS
#include "Hubble.h"             //Hubble
#include "Dragon.h"             //Dragon
#include "StarLink.h"           //Starlink
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
      colliders = list<SpaceCollider*>();
       
       // Sputnik
       Position sputnikPos = Position();
       sputnikPos.setMeters(-36515095.13, 21082000.0);
       Velocity sputnikVel;
       sputnikVel = Velocity(2050.0, 2684.68);
       sputnik = Sputnik(sputnikPos, sputnikVel);
       
       //First GPS
       Position gpsPos1 = Position();
       gpsPos1.setMeters(0, 26560000.0);
       Velocity gpsVel1;
       gpsVel1 = Velocity(-3880.0, 0.0);
       gps1 = GPS(gpsPos1, gpsVel1);
       
       //Second GPS
       Position gpsPos2 = Position();
       gpsPos2.setMeters(23001634.72, 13280000.0);
       Velocity gpsVel2;
       gpsVel2 = Velocity(-1940.00, 3360.18);
       gps2 = GPS(gpsPos2, gpsVel2);
       
       //Third GPS
       Position gpsPos3 = Position();
       gpsPos3.setMeters(23001634.72, -13280000.0);
       Velocity gpsVel3;
       gpsVel3 = Velocity(1940.00, 3360.18);
       gps3 = GPS(gpsPos3, gpsVel3);
       
       //Fourth GPS
       Position gpsPos4 = Position();
       gpsPos4.setMeters(0, -26560000.0);
       Velocity gpsVel4;
       gpsVel4 = Velocity(3880.0, 0.0);
       gps4 = GPS(gpsPos4, gpsVel4);
       
       //Fifth GPS
       Position gpsPos5 = Position();
       gpsPos5.setMeters(-23001634.72, -13280000.0);
       Velocity gpsVel5;
       gpsVel5 = Velocity(1940.00, -3360.18);
       gps5 = GPS(gpsPos5, gpsVel5);
       
       //Sixth GPS
       Position gpsPos6 = Position();
       gpsPos6.setMeters(-23001634.72, 13280000.0);
       Velocity gpsVel6;
       gpsVel6 = Velocity(-1940.00, -3360.18);
       gps6 = GPS(gpsPos6, gpsVel6);
       
       
       //Hubble
       Position hubblePos = Position();
       hubblePos.setMeters(0.0, -42164000.0);
       Velocity hubbleVel;
       hubbleVel = Velocity(3100.0, 0.0);
       hubble = Hubble(hubblePos, hubbleVel);
       
       //Dragon
       Position dragonPos = Position();
       dragonPos.setMeters(0.0, 8000000.0);
       Velocity dragonVel;
       dragonVel = Velocity(-7900.0, 0.0);
       dragon = Dragon(dragonPos, dragonVel);
       
       //Starlink
       Position starlinkPos = Position();
       starlinkPos.setMeters(0.0, -13020000.0);
       Velocity starlinkVel;
       starlinkVel = Velocity(5800.0, 0.0);
       starlink = StarLink(starlinkPos, starlinkVel);
       
       
      Position shipPos = Position();
      shipPos.setPixelsX(-450);
      shipPos.setPixelsY(450);
      Velocity shipVel = Velocity(0, -2000);
      player = Ship(shipPos, shipVel);
      colliders.push_back(&player);
      colliders.push_back(&sputnik);
       colliders.push_back(&hubble);
       colliders.push_back(&dragon);
       colliders.push_back(&starlink);
       
       colliders.push_back(&gps1);
       colliders.push_back(&gps2);
       colliders.push_back(&gps3);
       colliders.push_back(&gps4);
       colliders.push_back(&gps5);
       colliders.push_back(&gps6);
       
       
       
      totalSeconds = 0;

      angleEarth = Angle(0.0, true);
      phaseStar = 0;
   }

   void nextFrame(const Interface* pUI)
   {
      handleCollisions();
      handleInputs(pUI);
      advance(TIME_DILATION / FRAME_RATE);
      display();
   }

private:

   void handleCollisions()
   {

   }

   void handleInputs(const Interface* pUI)
   {
      player.thrustForward(pUI->isDown());
      if (pUI->isLeft())
         player.thrustLeft();
      if (pUI->isRight())
         player.thrustRight();
      if (pUI->isSpace())
         player.fire(colliders);
   }

   // TODO: When checking if two things collide, make sure they both aren't dead.
   // move and rotate everything according to the amount of time that has passed.
   void advance(double elapsedSeconds)
   {
      totalSeconds += elapsedSeconds;
      // rotate the earth, and advance the star phase
      double rotationAmount = -(2 * PI / SECONDS_PER_DAY) * elapsedSeconds;
      angleEarth.addRadians(rotationAmount);
      phaseStar++;

      // move things
      for (SpaceCollider* collider : colliders)
      {
         collider->advance(elapsedSeconds);
      }
   }

   void display()
   {
      for(SpaceCollider* collider : colliders)
      {
         collider->draw();
      }
      
      drawStar(ptStar, phaseStar);

      // draw the earth
      Position pt = Position(0.0, 0.0);
      drawEarth(pt, angleEarth.getRadians());
   }

   list<SpaceCollider*> colliders;
   Ship player;
    
    Sputnik sputnik;
    Hubble hubble;
    Dragon dragon;
    StarLink starlink;
    
    GPS gps1;
    GPS gps2;
    GPS gps3;
    GPS gps4;
    GPS gps5;
    GPS gps6;
    
    Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStar;
   int totalSeconds;
    
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
   pGame->nextFrame(pUI);
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
