#include "Renderer.Editor.Cell.h"
#include "Common.XY.h"
#include "Aspirant.Context.Editor.Cell.h"
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

	void Draw(SDL_Renderer* renderer)
	{
		auto& objs = aspirant::context::editor::Cell::GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			obj->Draw(renderer, Plot({ column++, 0 }));
		}
		graphics::Sprites::Get(SPRITE_CURSOR).Draw(renderer, Plot({ aspirant::context::editor::Cell::GetIndex(), 0 }));
	}
}