#include "RoomRenderer.h"
#include "XY.h"
#include "EditorRoomViewContext.h"
#include "SpriteManager.h"
#include "EditorRoomListContext.h"
#include "EditorBaseControl.h"
namespace aspirant::editor::controls::RoomRenderer
{
	static tggd::common::XY<int> Plot(const tggd::common::XY<size_t>& position)
	{
		return tggd::common::XY<int>((int)position.GetX() * 36, (int)position.GetY() * 36);
	}

	static void DrawCell(SDL_Renderer* renderer, const tggd::common::XY<size_t>& viewPosition, const aspirant::game::ScenarioRoomCell* cell)
	{
		if (cell)
		{
			auto& objs = cell->GetObjects();
			for (auto& obj : objs)
			{
				auto plotPosition = Plot(viewPosition);
				aspirant::editor::controls::EditorBaseControl::DrawObject(renderer, plotPosition, obj);
			}
		}
	}

	static void DrawRoom(SDL_Renderer* renderer, const aspirant::game::ScenarioRoom* room)
	{
		if (room)
		{
			for (size_t viewRow = 0; viewRow < aspirant::editor::context::EditorRoomViewContext::GetSize().GetY(); ++viewRow)
			{
				for (size_t viewColumn = 0; viewColumn < aspirant::editor::context::EditorRoomViewContext::GetSize().GetX(); ++viewColumn)
				{
					tggd::common::XY<size_t> viewPosition =
						tggd::common::XY<size_t>
						(
							viewColumn,
							viewRow
							);
					tggd::common::XY<size_t> cellPosition =
						viewPosition + aspirant::editor::context::EditorRoomViewContext::GetAnchor();
					auto cell = room->GetCell(cellPosition.GetX(), cellPosition.GetY());
					if (cell)
					{
						auto& objs = cell->GetObjects();
						for (auto& obj : objs)
						{
							auto plotPosition = Plot(viewPosition);
							aspirant::editor::controls::EditorBaseControl::DrawObject(renderer, plotPosition, obj);
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
		auto& cursorPosition = aspirant::editor::context::EditorRoomViewContext::GetCursor();
		auto& anchorPosition = aspirant::editor::context::EditorRoomViewContext::GetAnchor();
		tggd::common::XY<size_t> viewPosition = { cursorPosition.GetX() - anchorPosition.GetX(), cursorPosition.GetY() - anchorPosition.GetY() };
		//TODO: magic string vv
		tggd::graphics::SpriteManager::Get("MapCursor").Draw(renderer, Plot(viewPosition));
	}

	void Draw(SDL_Renderer* renderer)
	{
		DrawRoom(renderer, aspirant::editor::context::EditorRoomListContext::GetRoom());
		DrawMapCursor(renderer);
	}
}