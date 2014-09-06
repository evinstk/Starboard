#include "State.h"
#include "Clock.h"

namespace temm
{

	State::State()
		: m_pStateStack(nullptr)
	{
	}

	State::State(StateStack& ss)
		: m_pStateStack(&ss)
	{
	}

	void RunState(State& state, SDL_Window& window, std::function<bool()> exitFunction)
	{
		Uint32 timeSinceLastUpdate = 0;
		Uint32 timePerFrame = 17;
		temm::Clock clock;
		SDL_Surface* screenSurface = SDL_GetWindowSurface(&window);

		while (!exitFunction())
		{
			Uint32 dt = clock.restart();
			timeSinceLastUpdate += dt;
			while (timeSinceLastUpdate > timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				state.VProcessInput();
				state.VUpdate(timePerFrame);
			}
			state.VDraw(*screenSurface);
			SDL_UpdateWindowSurface(&window);
		}
	}

}
