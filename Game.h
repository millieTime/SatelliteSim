/*************************************************************
 * 1. Name:
 *      Satellite Simulator
 * 2. Assignment Name:
 *      Lab 11: Code Complete
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#ifndef Game_h
#define Game_h

#include <stdio.h>
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
#include "Earth.h"         //Earth
using namespace std;

/*************************************************************************
 * Game
 * Plays the game of Satellite Simulator
 *************************************************************************/
class Game
{
public:
    // Game constructor with a given position object
    Game(Position ptUpperRight);
    
   /************************************************************
   * GAME : NEXT FRAME
   *   Handles collisions, responds to inputs, moves the objects,
   *   and draws the screen
   *************************************************************/
    void nextFrame(const Interface* pUI);

private:
    // Star struct with a position and phase
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
    void handleCollisions();
   
   /**********************************************************
   * GAME : HANDLE INPUTS
   *   Tells the player ship which keys are being pressed.
   ***********************************************************/
    void handleInputs(const Interface* pUI);

   /**********************************************************
   * GAME : ADVANCE
   *   Moves and rotates all the items in colliders. phases up the stars,
   *   and rotates the earth.
   ***********************************************************/
    void advance(double elapsedSeconds);
    
    // Display all the objects such spacecolliders, earth and stars
    void display();
    
   list<SpaceCollider*> colliders;
   Ship player;
   Star stars[NUM_STARS];
   Position ptUpperRight;
   Earth earth;
};

#endif /* Game_h */
