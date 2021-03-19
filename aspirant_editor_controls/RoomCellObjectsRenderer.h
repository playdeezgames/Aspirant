#pragma once
#include "EditorBaseControl.h"
#include "EditorContext.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsRenderer : public EditorBaseControl<aspirant::editor::context::EditorContext>
	{
		RoomCellObjectsRenderer() = delete;
		RoomCellObjectsRenderer(const RoomCellObjectsRenderer&) = delete;
		RoomCellObjectsRenderer(RoomCellObjectsRenderer&&) = delete;
		RoomCellObjectsRenderer& operator=(const RoomCellObjectsRenderer&) = delete;
		RoomCellObjectsRenderer& operator=(RoomCellObjectsRenderer&&) = delete;
	public:
		RoomCellObjectsRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}
