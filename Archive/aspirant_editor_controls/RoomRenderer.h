#pragma once
#include "EditorContext.h"
#include "EditorBaseControl.h"
namespace aspirant::editor::controls
{
	class RoomRenderer: public EditorBaseControl<aspirant::editor::context::EditorContext>
	{
		RoomRenderer() = delete;
		RoomRenderer(const RoomRenderer&) = delete;
		RoomRenderer(RoomRenderer&&) = delete;
		RoomRenderer& operator=(const RoomRenderer&) = delete;
		RoomRenderer& operator=(RoomRenderer&&) = delete;
	private:
		void DrawCell(SDL_Renderer*, const tggd::common::XY<size_t>&, const aspirant::game::ScenarioRoomCell*) const;
		void DrawRoom(SDL_Renderer*, const aspirant::game::ScenarioRoom*) const;
		void DrawMapCursor(SDL_Renderer*) const;
	public:
		RoomRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}
