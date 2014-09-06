#include "TestState.h"
#include <SDL.h>

namespace temm
{

	std::shared_ptr<SDL_Surface> LoadSurface(const std::string& path)
	{
		//Load image at specified path
		SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
		if( loadedSurface == NULL )
		{
			std::string message(SDL_GetError());
			throw std::runtime_error("Failed to load image: " + message);
		}
		return std::shared_ptr<SDL_Surface>(loadedSurface, SDL_FreeSurface);
	}

	TestState::TestState()
		: State()
		, m_InitObj()
		, m_Surfaces()
		, m_CurrSurfaceI(DEFAULT)
		, m_PixelX(5.f)
		, m_PixelY(5.f)
		, m_PixelDx(0)
		, m_PixelDy(0)
	{
		m_Surfaces[DEFAULT] = LoadSurface("../../../Assets/press.bmp");
		m_Surfaces[UP] = LoadSurface("../../../Assets/up.bmp");
		m_Surfaces[DOWN] = LoadSurface("../../../Assets/down.bmp");
		m_Surfaces[LEFT] = LoadSurface("../../../Assets/left.bmp");
		m_Surfaces[RIGHT] = LoadSurface("../../../Assets/right.bmp");
	}

	bool TestState::VProcessInput()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type = SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					m_CurrSurfaceI = UP;
					m_PixelDy = -0.05f;
					break;
				case SDLK_DOWN:
					m_CurrSurfaceI = DOWN;
					m_PixelDy = 0.05f;
					break;
				case SDLK_LEFT:
					m_CurrSurfaceI = LEFT;
					m_PixelDx = -0.05f;
					break;
				case SDLK_RIGHT:
					m_CurrSurfaceI = RIGHT;
					m_PixelDx = 0.05f;
					break;
				default:
					m_CurrSurfaceI = DEFAULT;
					break;
				}
			}
		}
		return false;
	}

	bool TestState::VUpdate(unsigned int dt)
	{
		m_PixelX += m_PixelDx * dt;
		m_PixelY += m_PixelDy * dt;
		return false;
	}

	void TestState::VDraw(SDL_Surface& surface)
	{
		SDL_Surface* src_surface = m_Surfaces[m_CurrSurfaceI].get();

		SDL_Rect destRect;
		destRect.x = m_PixelX;
		destRect.y = m_PixelY;

		SDL_BlitSurface(src_surface, NULL, &surface, &destRect);
	}

}
