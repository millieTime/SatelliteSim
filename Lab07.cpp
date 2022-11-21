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
      Position shipPos = Position();
      shipPos.setPixelsX(-450);
      shipPos.setPixelsY(450);
      Velocity shipVel = Velocity(0, -2000);
      player = Ship(shipPos, shipVel);
      colliders.push_back(&player);

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
