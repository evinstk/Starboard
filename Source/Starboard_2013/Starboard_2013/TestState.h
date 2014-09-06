#ifndef _TEST_STATE_H_
#define _TEST_STATE_H_

#include "State.h"
#include "SDL_Initialization.h"

#include <array>

namespace temm
{

	class TestState : public State
	{
	public:
		TestState();

		bool VProcessInput();
		bool VUpdate(Uint32 dt);
		void VDraw(SDL_Surface& surface);

	private:
		enum KeySurface
		{
			DEFAULT,
			UP,
			DOWN,
			LEFT,
			RIGHT,
			SURFACE_COUNT,
		};

		SDL_Initialization m_InitObj;
		std::array
		<
			std::shared_ptr<SDL_Surface>,
			SURFACE_COUNT
		> m_Surfaces;
		KeySurface m_CurrSurfaceI;

		float m_PixelX;
		float m_PixelY;
		float m_PixelDx;
		float m_PixelDy;
	};

}

#endif /* _TEST_STATE_H */
