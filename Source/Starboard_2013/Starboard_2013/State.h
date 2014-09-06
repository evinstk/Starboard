#ifndef _STATE_H_
#define _STATE_H_

#include <SDL_atomic.h>

#include <memory>
#include <vector>
#include <functional>

struct SDL_Surface;
struct SDL_Window;

namespace temm
{

	enum class StateAction
	{
		PUSH,
		POP,
		CLEAR,
	};

	enum class StateType
	{
		NO_STATE,
		TEST_STATE,
	};

	struct StateBroadcast
	{
		StateAction action;
		StateType type;
		StateBroadcast(StateAction action, StateType type)
			: action(action)
			, type(type)
		{}
	};

	class IStateListener
	{
	public:
		virtual ~IStateListener() {}
		virtual void VListen(const StateBroadcast& message) = 0;
	};

	class State
	{
	public:
		State();
		virtual ~State() {}

		virtual bool VProcessInput() = 0;
		virtual bool VUpdate(Uint32 dt) = 0;
		virtual void VDraw(SDL_Surface& surface) = 0;

		void AttachListener(std::shared_ptr<IStateListener> pListener);
		void DetachListener(std::shared_ptr<IStateListener> pListener);

	protected:
		void BroadcastPush(StateType stateType);
		void BroadcastPop();
		void BroadcastClear();

	private:
		void Broadcast(const StateBroadcast& message);

		std::vector<std::weak_ptr<IStateListener>> m_Listeners;
	};

	void RunState(State& state, SDL_Window& surface, std::function<bool()> exitFunction);

}

#endif
