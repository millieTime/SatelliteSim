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
         Star star = { Position(random(-450, 450) * ptUpperRight.getZoom(), random(-450, 450) * ptUpperRight.getZoom()), phase};
         stars[i] = star;
      }
       // Create a list of colliders
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
       
       // SHIP
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

