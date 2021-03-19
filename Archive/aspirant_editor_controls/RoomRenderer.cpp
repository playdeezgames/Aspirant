#include "RoomRenderer.h"
namespace aspirant::editor::controls
{
	class RoomRendererPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::common::XY<int> Plot(const tggd::common::XY<size_t>& position) const
		{
			return tggd::common::XY<int>((int)position.GetX() * 36, (int)position.GetY() * 36);//TODO: magic number
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

	void RoomRenderer::DrawCell(SDL_Renderer* renderer, const tggd::common::XY<size_t>& viewPosition, const aspirant::game::ScenarioRoomCell* cell) const
	{
		if (cell)
		{
			auto& objs = cell->GetObjects();
			for (auto& obj : objs)
			{
				auto plotPosition = GetPlotter()->Plot(viewPosition);
				DrawObject(renderer, plotPosition, obj);
			}
		}
	}


	void RoomRenderer::DrawRoom(SDL_Renderer* renderer, const aspirant::game::ScenarioRoom* room) const
	{
		if (room)
		{
			for (size_t viewRow = 0; viewRow < GetContext().GetRoomView().GetSize().GetY(); ++viewRow)
			{
				for (size_t viewColumn = 0; viewColumn < GetContext().GetRoomView().GetSize().GetX(); ++viewColumn)
				{
					tggd::common::XY<size_t> viewPosition =
						tggd::common::XY<size_t>
						(
							viewColumn,
							viewRow
							);
					tggd::common::XY<size_t> cellPosition =
						viewPosition + GetContext().GetRoomView().GetAnchor();
					auto cell = room->GetCell(cellPosition.GetX(), cellPosition.GetY());
					if (cell)
					{
						auto& objs = cell->GetObjects();
						for (auto& obj : objs)
						{
							auto plotPosition = GetPlotter()->Plot(viewPosition);
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
		auto& cursorPosition = GetContext().GetRoomView().GetCursor();
		auto& anchorPosition = GetContext().GetRoomView().GetAnchor();
		tggd::common::XY<size_t> viewPosition = { cursorPosition.GetX() - anchorPosition.GetX(), cursorPosition.GetY() - anchorPosition.GetY()  };
		//TODO: magic string vv
		GetSpriteManager()["MapCursor"].Draw(renderer, GetPlotter()->Plot(viewPosition));
	}

	void RoomRenderer::Draw(SDL_Renderer* renderer) const
	{
		DrawRoom(renderer, GetContext().GetRoomList().GetRoom());
		DrawMapCursor(renderer);
	}
}