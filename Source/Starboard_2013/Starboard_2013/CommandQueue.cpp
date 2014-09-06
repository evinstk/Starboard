#include "CommandQueue.h"

namespace temm
{

	CommandQueue::CommandQueue()
		: m_Queue()
	{
	}

	void CommandQueue::Insert(std::shared_ptr<ICommand> command)
	{
		m_Queue.push(command);
	}

	std::shared_ptr<ICommand> CommandQueue::Pop()
	{
		if (m_Queue.empty())
		{
			std::shared_ptr<ICommand> ret(nullptr);
			return ret;
		}
		else
		{
			std::shared_ptr<ICommand> ret(m_Queue.front());
			m_Queue.pop();
			return ret;
		}
	}

}
