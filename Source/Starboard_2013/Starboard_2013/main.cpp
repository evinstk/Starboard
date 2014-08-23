#include "SDL_Initialization.h"
#include "Clock.h"
#include <SDL.h>

int main(int argc, char* argv[])
{
	temm::SDL_Initialization initObj(SDL_INIT_VIDEO);
	std::shared_ptr<SDL_Window> window(SDL_CreateWindow("Starboard",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1024,
		768,
		SDL_WINDOW_SHOWN), SDL_DestroyWindow);

	Uint32 timeSinceLastUpdate = 0;
	Uint32 timePerFrame = 17;
	bool bQuit = false;
	temm::Clock clock;
	while (!bQuit)
	{
		Uint32 dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			// processInput();
			// update(timePerFrame);
		}
		bQuit = true;
		// render();
	}

	return 0;
}
