#pragma once
#include "EditorBaseControl.h"
namespace aspirant::editor::controls
{
	class RoomRenderer: public EditorBaseControl
	{
	private:
		void DrawObject(SDL_Renderer*, const tggd::graphics::XY<int>&, const aspirant::game::ScenarioObjectInstance*) const;
		void DrawCell(SDL_Renderer*, const tggd::graphics::XY<size_t>&, const aspirant::game::ScenarioRoomCell*) const;
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
