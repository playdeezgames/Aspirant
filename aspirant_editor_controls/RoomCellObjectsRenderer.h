#pragma once
#include "EditorBaseControl.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsRenderer : public EditorBaseControl
	{
	private:
		void DrawObject(SDL_Renderer*, tggd::graphics::XY<int>, const aspirant::game::ScenarioObjectInstance*) const;
	public:
		RoomCellObjectsRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}
