#include "Common.XY.h"
#include "Context.Editor.Cell.h"
#include "Graphics.Sprites.h"
namespace renderer::editor::RoomCellObjects
{
	const std::string SPRITE_CURSOR = "MapCursor";
	const int OFFSET_X = 360;
	const int OFFSET_Y = 0;
	const int TILE_WIDTH = 36;

	common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return { OFFSET_X + (int)position.GetX() * TILE_WIDTH, OFFSET_Y };
	}

	void Draw(SDL_Renderer* renderer, const nlohmann::json&)
	{
		auto objs = context::editor::Cell::GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			obj.Draw(renderer, Plot({ column++, 0 }));
		}
		graphics::Sprites::Read(SPRITE_CURSOR).value().Draw(renderer, Plot({ ::context::editor::Cell::GetIndex(), 0 }));
	}
}