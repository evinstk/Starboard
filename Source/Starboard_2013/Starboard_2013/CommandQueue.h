#ifndef _COMMAND_QUEUE_H_
#define _COMMAND_QUEUE_H_

#include <queue>
#include <memory>

namespace temm
{
	class ICommand;

	class CommandQueue
	{
	public:
		CommandQueue();

		void Insert(std::shared_ptr<ICommand> command);
		std::shared_ptr<ICommand> Pop();

	private:
		std::queue<std::shared_ptr<ICommand>> m_Queue;
	};

}

#endif /* _COMMAND_STREAM_H_ */
