#pragma once
#include <SDL.h>
#include "Drawn.h"
#include "EditorContext.h"
#include "XY.h"
namespace aspirant::editorui
{
	class RoomRenderer: tggd::graphics::Drawn
	{
	private:
		const EditorContext& editorContext;

	public:
		RoomRenderer
		(
			const EditorContext&
		);
		void Draw(SDL_Renderer*) const;
	};
}
