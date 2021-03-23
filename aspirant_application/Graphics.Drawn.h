#pragma once
#include <SDL.h>
namespace graphics
{
	class Drawn
	{
	public:
		virtual void Draw(SDL_Renderer*) const = 0;
	};
}
