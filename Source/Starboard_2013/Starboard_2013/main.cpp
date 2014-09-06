#include "SDL_Initialization.h"
#include "TestState.h"
#include "Clock.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		temm::SDL_Initialization initObj(SDL_INIT_VIDEO);
		std::shared_ptr<SDL_Window> window(SDL_CreateWindow("Starboard",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1024,
			768,
			SDL_WINDOW_SHOWN), SDL_DestroyWindow);

		temm::TestState state;
		RunState(state, *window.get(), []{ return false; });
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
