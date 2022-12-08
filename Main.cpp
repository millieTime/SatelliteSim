/***************************************************************************************
 * Source File:
 *    Main: Sets up the game starts the callback cycle.
 * Author:
 *    Preston Millward and Gergo Medveczky
 * Summary:
 *    Play the satellite game
 ***************************************************************************************/
#include "Game.h"
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


