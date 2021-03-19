#include "RoomCellObjectsRenderer.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::common::XY<int> Plot(const tggd::common::XY<size_t>& position) const
		{
			return {360 + (int)position.GetX() * 36, 0 };//TODO: magic numbers
		}
	};

	RoomCellObjectsRenderer::RoomCellObjectsRenderer
	(
		const aspirant::editor::context::EditorContext& editorContext,
		const tggd::graphics::SpriteManager& spriteManager
	)
		: EditorBaseControl(editorContext, spriteManager, new RoomCellObjectsPlotter())
	{

	}

	void RoomCellObjectsRenderer::Draw(SDL_Renderer* renderer) const
	{
		auto& objs = GetContext().GetRoomCellObjects().GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			DrawObject(renderer, GetPlotter()->Plot({ column++, 0 }), obj);
		}
		GetSpriteManager()["MapCursor"].Draw(renderer, GetPlotter()->Plot({ GetContext().GetRoomCellObjects().GetIndex(), 0 }));
	}
}