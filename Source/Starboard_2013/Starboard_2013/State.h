#ifndef _STATE_H_
#define _STATE_H_

#include <SDL_atomic.h>

#include <functional>

struct SDL_Surface;
struct SDL_Window;

namespace temm
{
	class StateStack;

	class State
	{
	public:
		State();
		State(StateStack& ss);

		~State() {}

		virtual bool VProcessInput() = 0;
		virtual bool VUpdate(Uint32 dt) = 0;
		virtual void VDraw(SDL_Surface& surface) = 0;

	private:
		StateStack* m_pStateStack;
	};

	void RunState(State& state, SDL_Window& surface, std::function<bool()> exitFunction);

}

#endif
