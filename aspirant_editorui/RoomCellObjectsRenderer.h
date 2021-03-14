#pragma once
#include "Drawn.h"
namespace aspirant::editorui
{
	class RoomCellObjectsRenderer : public tggd::graphics::Drawn
	{
	private:
	public:
		RoomCellObjectsRenderer();
		void Draw(SDL_Renderer*) const;
	};
}
