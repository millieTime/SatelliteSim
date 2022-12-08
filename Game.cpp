/***************************************************************************************
 * Source File:
 *    Game function implementations
 * Author:
 *    Preston Millward and Gergo Medveczky
 ***************************************************************************************/

#include "Game.h"

   // Game constructor with a given position object
   Game::Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      // Create stars
      for (int i = 0; i < NUM_STARS; i++)
      {
         unsigned char phase = random(0, 255);
         stars[i] = { Position(random(-450, 450) * ptUpperRight.getZoom(), random(-450, 450) * ptUpperRight.getZoom()), phase };
      }
      // Create a list of colliders
      colliders = list<SpaceCollider*>();

      // Sputnik
      colliders.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68)));
      // Hubble
      colliders.push_back(new Hubble(Position(0.0, -42164000.0), Velocity(3100.0, 0.0)));
      // Dragon
      colliders.push_back(new Dragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0)));
      // Starlink
      colliders.push_back(new StarLink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0)));
      // GPS
      colliders.push_back(new GPS(Position(0, 26560000.0), Velocity(-3880.0, 0.0)));
      colliders.push_back(new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18)));
      colliders.push_back(new GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18)));
      colliders.push_back(new GPS(Position(0, -26560000.0), Velocity(3880.0, 0.0)));
      colliders.push_back(new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18)));
      colliders.push_back(new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18)));

      // Ship
      player = Ship(Position(-450.0 * ptUpperRight.getZoom(), 450.0 * ptUpperRight.getZoom()), Velocity(0, -2000));
      colliders.push_back(&player);
      
      angleEarth = Angle(0.0, true);
   }

   /************************************************************
   * GAME : NEXT FRAME
   *   Handles collisions, responds to inputs, moves the objects,
   *   and draws the screen
   *************************************************************/
   void Game::nextFrame(const Interface* pUI)
   {
      handleInputs(pUI);
      advance(TIME_DILATION / FRAME_RATE);
      handleCollisions();
      display();
   }
   /**********************************************************
   * GAME : HANDLE COLLISIONS
   *   Loops through each item in colliders and checks whether that
   *   item is sharing space with something else. If it is, tells both
   *   items to do their collision logic. In a separate loop, it removes
   *   dead items from the colliders list.
   ***********************************************************/
   void Game::handleCollisions()
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
   void Game::handleInputs(const Interface* pUI)
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
   void Game::advance(double elapsedSeconds)
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
    
   // Display all the objects such spacecolliders, earth and stars
   void Game::display()
   {
      for (int i = 0; i < NUM_STARS; i++)
         drawStar(stars[i].pos, stars[i].phase);
      
      for(SpaceCollider* collider : colliders)
         collider->draw();

      // draw the earth
      Position pt = Position(0.0, 0.0);
      drawEarth(pt, angleEarth.getRadians());
   }

