#ifndef _SDL_INITIALIZATION_H_
#define _SDL_INITIALIZATION_H_

#include <SDL_atomic.h>

#include <memory>

namespace temm
{

	class SDL_Initialization
	{
	public:
		SDL_Initialization(Uint32 flags=0);
		~SDL_Initialization();
		SDL_Initialization(const SDL_Initialization&);
	private:
		SDL_Initialization& operator=(const SDL_Initialization&);
		static int m_RefCount;
	};

}

#endif /* _SDL_INITIALIZATION_H_ */
