#include "Renderer.Editor.Room.h"
#include "Common.XY.h"
#include "Aspirant.Context.Editor.RoomView.h"
#include "SpriteManager.h"
#include "Aspirant.Context.Editor.RoomList.h"
#include "Renderer.Editor.Common.h"
namespace renderer::editor::Room
{
	static common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return common::XY<int>((int)position.GetX() * 36, (int)position.GetY() * 36);
	}

	static void DrawCell(SDL_Renderer* renderer, const common::XY<size_t>& viewPosition, const ::game::Cell* cell)
	{
		if (cell)
		{
			auto& objs = cell->GetObjects();
			for (auto& obj : objs)
			{
				auto plotPosition = Plot(viewPosition);
				renderer::editor::Common::DrawObject(renderer, plotPosition, obj);
			}
		}
	}

	static void DrawRoom(SDL_Renderer* renderer, const ::game::Room* room)
	{
		if (room)
		{
			for (size_t viewRow = 0; viewRow < aspirant::context::editor::RoomView::GetSize().GetY(); ++viewRow)
			{
				for (size_t viewColumn = 0; viewColumn < aspirant::context::editor::RoomView::GetSize().GetX(); ++viewColumn)
				{
					common::XY<size_t> viewPosition =
						common::XY<size_t>
						(
							viewColumn,
							viewRow
							);
					common::XY<size_t> cellPosition =
						viewPosition + aspirant::context::editor::RoomView::GetAnchor();
					auto cell = room->GetCell(cellPosition.GetX(), cellPosition.GetY());
					if (cell)
					{
						auto& objs = cell->GetObjects();
						for (auto& obj : objs)
						{
							auto plotPosition = Plot(viewPosition);
							renderer::editor::Common::DrawObject(renderer, plotPosition, obj);
						}
					}
				}
			}
		}
	}

	static void DrawMapCursor(SDL_Renderer* renderer)
	{
		//MapCursor
		//vp = cp - an
		auto& cursorPosition = aspirant::context::editor::RoomView::GetCursor();
		auto& anchorPosition = aspirant::context::editor::RoomView::GetAnchor();
		common::XY<size_t> viewPosition = { cursorPosition.GetX() - anchorPosition.GetX(), cursorPosition.GetY() - anchorPosition.GetY() };
		//TODO: magic string vv
		tggd::graphics::SpriteManager::Get("MapCursor").Draw(renderer, Plot(viewPosition));
	}

	void Draw(SDL_Renderer* renderer)
	{
		DrawRoom(renderer, aspirant::context::editor::RoomList::GetRoom());
		DrawMapCursor(renderer);
	}
}