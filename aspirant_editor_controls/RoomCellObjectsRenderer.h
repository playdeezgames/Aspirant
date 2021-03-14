#pragma once
#include "EditorBaseControl.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsRenderer : public EditorBaseControl
	{
	public:
		RoomCellObjectsRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}
