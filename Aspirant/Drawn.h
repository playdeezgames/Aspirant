#pragma once
#include <SDL.h>
namespace tggd::common
{
	class Drawn
	{
	public:
		virtual void Draw(SDL_Renderer*) const = 0;
	};
}
