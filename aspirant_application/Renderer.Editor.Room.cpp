#include "Common.XY.h"
#include "Context.Editor.RoomView.h"
#include "Graphics.Sprites.h"
#include "Context.Editor.Rooms.h"
namespace renderer::editor::Room
{
	const std::string SPRITE_CURSOR = "MapCursor";
	const int OFFSET_X = 0;
	const int OFFSET_Y = 0;
	const int TILE_WIDTH = 36;
	const int TILE_HEIGHT = 36;

	static common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return common::XY<int>(OFFSET_X + (int)position.GetX() * TILE_WIDTH, OFFSET_Y + (int)position.GetY() * TILE_HEIGHT);
	}

	static void DrawCell(SDL_Renderer* renderer, const common::XY<size_t>& viewPosition, const std::optional<game::Cell>& cell)
	{
		if (cell.has_value())
		{
			auto objs = cell->GetObjects();
			for (auto& obj : objs)
			{
				obj.Draw(renderer, Plot(viewPosition));
			}
		}
	}

	static void DrawRoom(SDL_Renderer* renderer, game::Room& room)
	{
		for (size_t viewRow = 0; viewRow < ::context::editor::RoomView::GetSize().GetY(); ++viewRow)
		{
			for (size_t viewColumn = 0; viewColumn < ::context::editor::RoomView::GetSize().GetX(); ++viewColumn)
			{
				common::XY<size_t> viewPosition =
					common::XY<size_t>(viewColumn, viewRow);
				common::XY<size_t> cellPosition =
					viewPosition + ::context::editor::RoomView::GetAnchor();
				auto cell = room.GetCell(cellPosition.GetX(), cellPosition.GetY());
				DrawCell(renderer, viewPosition, cell);
			}
		}
	}

	static void DrawMapCursor(SDL_Renderer* renderer)
	{
		auto& cursorPosition = ::context::editor::RoomView::GetCursor();
		auto& anchorPosition = ::context::editor::RoomView::GetAnchor();
		common::XY<size_t> viewPosition = { cursorPosition.GetX() - anchorPosition.GetX(), cursorPosition.GetY() - anchorPosition.GetY() };
		graphics::Sprites::Read(SPRITE_CURSOR).value().Draw(renderer, Plot(viewPosition));
	}

	void Draw(SDL_Renderer* renderer, const nlohmann::json&)
	{
		auto room = context::editor::Rooms::GetRoom();
		DrawRoom(renderer, room);
		DrawMapCursor(renderer);
	}
}