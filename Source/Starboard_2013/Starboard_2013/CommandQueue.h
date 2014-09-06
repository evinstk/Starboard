#ifndef _COMMAND_QUEUE_H_
#define _COMMAND_QUEUE_H_

#include <queue>
#include <memory>

namespace temm
{
	struct Command;

	class CommandQueue
	{
	public:
		CommandQueue();

		void Insert(std::shared_ptr<Command> command);
		std::shared_ptr<Command> Pop();

	private:
		std::queue<std::shared_ptr<Command>> m_Queue;
	};

}

#endif /* _COMMAND_STREAM_H_ */
