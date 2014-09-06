#include "State.h"
#include "Clock.h"

namespace temm
{

	State::State()
		: m_Listeners()
	{
	}

	void State::AttachListener(std::shared_ptr<IStateListener> pListener)
	{
		for (auto it = m_Listeners.begin(); it != m_Listeners.end(); ++it)
		{
			if (auto stp = it->lock())
			{
				if (pListener.get() == stp.get())
				{
					return;
				}
			}
		}
		// If it's not already in m_Listeners
		std::weak_ptr<IStateListener> wpListener(pListener);
		m_Listeners.push_back(wpListener);
	}

	void State::DetachListener(std::shared_ptr<IStateListener> pListener)
	{
		for (auto it = m_Listeners.begin(); it != m_Listeners.end(); ++it)
		{
			if (auto stp = it->lock())
			{
				if (pListener.get() == stp.get())
				{
					m_Listeners.erase(it);
					return;
				}
			}
		}
	}

	void State::BroadcastPush(StateType stateType)
	{
		StateBroadcast message(StateAction::PUSH, stateType);
		Broadcast(message);
	}

	void State::BroadcastPop()
	{
		StateBroadcast message(StateAction::POP, StateType::NO_STATE);
		Broadcast(message);
	}

	void State::BroadcastClear()
	{
		StateBroadcast message(StateAction::CLEAR, StateType::NO_STATE);
		Broadcast(message);
	}

	void State::Broadcast(const StateBroadcast& message)
	{
		for (auto it = m_Listeners.begin(); it != m_Listeners.end(); ++it)
		{
			if (auto stp = it->lock())
			{
				stp->VListen(message);
			}
		}
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
