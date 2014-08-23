#include "SDL_Initialization.h"

#include <SDL.h>

#include <stdexcept>

namespace temm
{

	int SDL_Initialization::m_RefCount(0);

	SDL_Initialization::SDL_Initialization(Uint32 flags)
	{
		if (m_RefCount == 0)
		{
			if (SDL_Init(flags) != 0)
			{
				std::string message(SDL_GetError());
				throw std::runtime_error("Failed to initialize SDL: " + message);
			}
		}
		++m_RefCount;
	}

	SDL_Initialization::~SDL_Initialization()
	{
		if (m_RefCount == 1)
		{
			SDL_Quit();
		}
		--m_RefCount;
	}

	SDL_Initialization::SDL_Initialization(const SDL_Initialization&)
	{
		++m_RefCount;
	}

}
