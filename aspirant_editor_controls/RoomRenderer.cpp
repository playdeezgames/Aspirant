#include "RoomRenderer.h"
namespace aspirant::editor::controls
{
	class RoomRendererPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::graphics::XY<int> Plot(const tggd::graphics::XY<size_t> position) const
		{
			return tggd::graphics::XY<int>((int)position.GetX() * 36, (int)position.GetY() * 36);//TODO: magic number
		}
	};

	RoomRenderer::RoomRenderer
	(
		const aspirant::editor::context::EditorContext& editorContext,
		const tggd::graphics::SpriteManager& spriteManager
	)
		: EditorBaseControl(editorContext, spriteManager, new RoomRendererPlotter())
	{

	}

	void RoomRenderer::DrawCell(SDL_Renderer* renderer, const tggd::graphics::XY<size_t>& viewPosition, const aspirant::game::ScenarioRoomCell* cell) const
	{
		if (cell)
		{
			auto& objs = cell->GetObjects();
			for (auto& obj : objs)
			{
				auto plotPosition = GetCellPlotter()->Plot(viewPosition);
				DrawObject(renderer, plotPosition, obj);
			}
		}
	}


	void RoomRenderer::DrawRoom(SDL_Renderer* renderer, const aspirant::game::ScenarioRoom* room) const
	{
		if (room)
		{
			for (size_t viewRow = 0; viewRow < GetEditorContext().GetRoomView().GetSize().GetY(); ++viewRow)
			{
				for (size_t viewColumn = 0; viewColumn < GetEditorContext().GetRoomView().GetSize().GetX(); ++viewColumn)
				{
					tggd::graphics::XY<size_t> viewPosition =
						tggd::graphics::XY<size_t>
						(
							viewColumn,
							viewRow
							);
					tggd::graphics::XY<size_t> cellPosition =
						viewPosition + GetEditorContext().GetRoomView().GetAnchor();
					auto cell = room->GetCell(cellPosition.GetX(), cellPosition.GetY());
					if (cell)
					{
						auto& objs = cell->GetObjects();
						for (auto& obj : objs)
						{
							auto plotPosition = GetCellPlotter()->Plot(viewPosition);
							DrawObject(renderer, plotPosition, obj);
						}
					}
				}
			}
		}
	}

	void RoomRenderer::DrawMapCursor(SDL_Renderer* renderer) const
	{
		//MapCursor
		//vp = cp - an
		auto& cursorPosition = GetEditorContext().GetRoomView().GetCursor();
		auto& anchorPosition = GetEditorContext().GetRoomView().GetAnchor();
		tggd::graphics::XY<size_t> viewPosition = { cursorPosition.GetX() - anchorPosition.GetX(), cursorPosition.GetY() - anchorPosition.GetY()  };
		//TODO: magic string vv
		GetSpriteManager().Get("MapCursor").Draw(renderer, GetCellPlotter()->Plot(viewPosition));
	}

	void RoomRenderer::Draw(SDL_Renderer* renderer) const
	{
		DrawRoom(renderer, GetEditorContext().GetRoomList().GetRoom());
		DrawMapCursor(renderer);
	}
}