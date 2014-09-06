#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <functional>
#include <cassert>

namespace temm
{

	class IGameObject;

	struct Command
	{
		typedef std::function<void(IGameObject&, Uint32 dt)> Action;

		Action action;
		Action undo;
		Command(Action action, Action undo = [](IGameObject&, Uint32){})
			: action(action)
			, undo(undo)
		{}
	};

	template<class DerivedObject, typename Function>
	Command::Action MakeAction(Function fn)
	{
		return[=](GameObject& gameObject, Uint32 dt)
		{
			assert(dynamic_cast<DerivedObject*>(&gameObject) != nullptr);
			fn(static_cast<DerivedObject&>(gameObject), dt);
		}
	}

}

#endif /* _COMMAND_H_ */
