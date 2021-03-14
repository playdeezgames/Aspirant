#include "RoomCellObjectsRenderer.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::graphics::XY<int> Plot(const tggd::graphics::XY<size_t> position) const
		{
			return tggd::graphics::XY<int>(360, (int)position.GetY() * 36);//TODO: magic numbers
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

	}
}