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

#include <cassert>         // for ASSERT
#include "test.h"          // for TEST
#include "uiInteract.h"    // for INTERFACE
#include "uiDraw.h"        // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "acceleration.h"  // for ACCELERATION
#include "velocity.h"      // for VELOCITY
#include "constants.h"     // for various constants
#include "SpaceCollider.h" // for all the space junk 
#include "ship.h"          // da ship
#include "Sputnik.h"       // Sputnik
#include "GPS.h"           //GPS
#include "Hubble.h"        //Hubble
#include "Dragon.h"        //Dragon
#include "StarLink.h"      //Starlink
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
      /*for (int i = 0; i < NUM_STARS; i++)
      {
         Star star = { Position(random(-450, 450) * ptUpperRight.getZoom(), random(-450, 450) * ptUpperRight.getZoom()), unsigned char(random(0, 255))};
         stars[i] = star;
      }*/

      colliders = list<SpaceCollider*>();
      
      // Sputnik
      Position sputnikPos = Position();
      sputnikPos.setMeters(-36515095.13, 21082000.0);
      Velocity sputnikVel;
      sputnikVel = Velocity(2050.0, 2684.68);
      SpaceCollider* sputnik = new Sputnik(sputnikPos, sputnikVel);
       
      //First GPS
      Position gpsPos1 = Position();
      gpsPos1.setMeters(0, 26560000.0);
      Velocity gpsVel1;
      gpsVel1 = Velocity(-3880.0, 0.0);
      SpaceCollider* gps1 = new GPS(gpsPos1, gpsVel1);
       
      //Second GPS
      Position gpsPos2 = Position();
      gpsPos2.setMeters(23001634.72, 13280000.0);
      Velocity gpsVel2;
      gpsVel2 = Velocity(-1940.00, 3360.18);
      SpaceCollider* gps2 = new GPS(gpsPos2, gpsVel2);
       
      //Third GPS
      Position gpsPos3 = Position();
      gpsPos3.setMeters(23001634.72, -13280000.0);
      Velocity gpsVel3;
      gpsVel3 = Velocity(1940.00, 3360.18);
      SpaceCollider* gps3 = new GPS(gpsPos3, gpsVel3);
       
      //Fourth GPS
      Position gpsPos4 = Position();
      gpsPos4.setMeters(0, -26560000.0);
      Velocity gpsVel4;
      gpsVel4 = Velocity(3880.0, 0.0);
      SpaceCollider* gps4 = new GPS(gpsPos4, gpsVel4);
       
      //Fifth GPS
      Position gpsPos5 = Position();
      gpsPos5.setMeters(-23001634.72, -13280000.0);
      Velocity gpsVel5;
      gpsVel5 = Velocity(1940.00, -3360.18);
      SpaceCollider* gps5 = new GPS(gpsPos5, gpsVel5);
       
      //Sixth GPS
      Position gpsPos6 = Position();
      gpsPos6.setMeters(-23001634.72, 13280000.0);
      Velocity gpsVel6;
      gpsVel6 = Velocity(-1940.00, -3360.18);
      SpaceCollider* gps6 = new GPS(gpsPos6, gpsVel6);
       
       
      //Hubble
      Position hubblePos = Position();
      hubblePos.setMeters(0.0, -42164000.0);
      Velocity hubbleVel;
      hubbleVel = Velocity(3100.0, 0.0);
      SpaceCollider* hubble = new Hubble(hubblePos, hubbleVel);
       
      //Dragon
      Position dragonPos = Position();
      dragonPos.setMeters(0.0, 8000000.0);
      Velocity dragonVel;
      dragonVel = Velocity(-7900.0, 0.0);
      SpaceCollider* dragon = new Dragon(dragonPos, dragonVel);
      
      //Starlink
      Position starlinkPos = Position();
      starlinkPos.setMeters(0.0, -13020000.0);
      Velocity starlinkVel;
      starlinkVel = Velocity(5800.0, 0.0);
      SpaceCollider* starlink = new StarLink(starlinkPos, starlinkVel);
       
      Position shipPos = Position();
      shipPos.setPixelsX(-450);
      shipPos.setPixelsY(450);
      Velocity shipVel = Velocity(0, -2000);
      player = Ship(shipPos, shipVel);
      SpaceCollider* shipPtr = &player;

      colliders.push_back(shipPtr);
      colliders.push_back(sputnik);
      colliders.push_back(hubble);
      colliders.push_back(dragon);
      colliders.push_back(starlink);
      
      colliders.push_back(gps1);
      colliders.push_back(gps2);
      colliders.push_back(gps3);
      colliders.push_back(gps4);
      colliders.push_back(gps5);
      colliders.push_back(gps6);
      

      angleEarth = Angle(0.0, true);
   }

   /************************************************************
   * GAME : NEXT FRAME
   *   Handles collisions, responds to inputs, moves the objects,
   *   and draws the screen
   *************************************************************/
   void nextFrame(const Interface* pUI)
   {
      handleInputs(pUI);
      advance(TIME_DILATION / FRAME_RATE);
      handleCollisions();
      display();
   }

private:

   struct Star
   {
      Position pos;
      unsigned char phase;
   };

   /**********************************************************
   * GAME : HANDLE COLLISIONS
   *   Loops through each item in colliders and checks whether that
   *   item is sharing space with something else. If it is, tells both
   *   items to do their collision logic. In a separate loop, it removes
   *   dead items from the colliders list.
   ***********************************************************/
   void handleCollisions()
   {
      Position earthPosition = Position(0.0, 0.0);

      // Main loop through all colliders
      for (auto cIter1 = colliders.begin(); cIter1 != colliders.end(); cIter1++)
      {
         SpaceCollider* collider1 = *cIter1;
         // Check earth collision first
         if (computeDistance(collider1->getCenter(), earthPosition) <= (collider1->getRadius() * earthPosition.getZoom() + EARTH_RADIUS))
            collider1->onCollision(colliders);
         // If this isn't dead,
         if (!collider1->isDead())
         {
            // inner loop through all colliders (make sure current otherItem isn't dead)
            for (auto cIter2 = next(cIter1, 1); cIter2 != colliders.end(); cIter2++)
            {
               SpaceCollider* collider2 = *cIter2;
               // if they collide, do collision work.
               if (!collider1->isDead() && !collider2->isDead() && collider1->isHitBy(collider2))
               {
                  collider1->onCollision(colliders);
                  collider2->onCollision(colliders);
               }
            }
         }
      }
      // Second loop through all colliders to remove dead ones.
      auto cIter = colliders.begin();
      while (cIter != colliders.end())
      {
         if ((*cIter)->isDead())
              cIter = colliders.erase(cIter);
         else
            cIter++;
      }
   }

   /**********************************************************
   * GAME : HANDLE INPUTS
   *   Tells the player ship which keys are being pressed.
   ***********************************************************/
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

   /**********************************************************
   * GAME : ADVANCE
   *   Moves and rotates all the items in colliders. phases up the stars,
   *   and rotates the earth.
   ***********************************************************/
   void advance(double elapsedSeconds)
   {
      // rotate the earth, and advance the star phase
      double rotationAmount = -(2 * PI / SECONDS_PER_DAY) * elapsedSeconds;
      angleEarth.addRadians(rotationAmount);

      // move things
      for (SpaceCollider* collider : colliders)
         collider->advance(elapsedSeconds);

      // phase up the stars
      for (int i = 0; i < NUM_STARS; i++)
         stars[i].phase++;
   }

   void display()
   {
      for (int i = 0; i < NUM_STARS; i++)
         drawStar(stars[i].pos, stars[i].phase);
      
      for(SpaceCollider* collider : colliders)
         collider->draw();

      // draw the earth
      Position pt = Position(0.0, 0.0);
      drawEarth(pt, angleEarth.getRadians());
   }

   list<SpaceCollider*> colliders;
   Ship player;
    
   Star stars[NUM_STARS];
   Position ptUpperRight;
    
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
