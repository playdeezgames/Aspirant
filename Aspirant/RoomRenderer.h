#pragma once
#include <SDL.h>
#include "Drawn.h"
namespace aspirant
{
	class RoomRenderer: tggd::graphics::Drawn
	{
	public:
		RoomRenderer();
		void Draw(SDL_Renderer*) const;
	};
}
