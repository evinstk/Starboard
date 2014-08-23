#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "SDL_Initialization.h"
#include <SDL.h>

namespace temm
{
	class Clock
	{
	public:
		Clock()
			: m_InitObj()
			, m_LastCallToRestart(SDL_GetTicks())
		{
		}

		Uint32 restart()
		{
			Uint32 newCall = SDL_GetTicks();
			Uint32 dt = newCall - m_LastCallToRestart;
			m_LastCallToRestart = newCall;
			return dt;
		}
	private:
		SDL_Initialization m_InitObj;
		Uint32 m_LastCallToRestart;
	};
}

#endif /* _CLOCK_H_ */
