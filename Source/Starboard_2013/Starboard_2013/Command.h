#ifndef _COMMAND_H_
#define _COMMAND_H_

namespace temm
{

	class IGameObject;

	class ICommand
	{
	public:
		virtual ~ICommand() {}
		virtual void VExecute(IGameObject& gameObject) = 0;
		virtual void VUndo(IGameObject& gameObject) {}
	};

}

#endif /* _COMMAND_H_ */
