#include "Renderer.Editor.PickDescriptor.h"
#include "Common.XY.h"
#include "Graphics.Sprites.h"
#include "Context.Editor.PickDescriptor.h"
namespace renderer::editor::PickDescriptor
{
	const std::string SPRITE_CURSOR = "MapCursor";
	const int OFFSET_X = 360;
	const int OFFSET_Y = 36;
	const int TILE_WIDTH = 36;
	const int TILE_HEIGHT = 36;
	const size_t TILE_COLUMNS = 7;

	common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return common::XY<int>(OFFSET_X + (int)position.GetX() * TILE_WIDTH, OFFSET_Y + (int)position.GetY() * TILE_HEIGHT);
	}

	void Draw(SDL_Renderer* renderer, const nlohmann::json&)
	{
		for (size_t idx = 0; idx < ::context::editor::PickDescriptor::GetCount(); ++idx)
		{
			common::XY<int> position = Plot({ idx % TILE_COLUMNS, idx / TILE_COLUMNS });

			context::editor::PickDescriptor::GetDescriptor(idx).Draw(renderer, position);

			if (idx == ::context::editor::PickDescriptor::GetIndex())
			{
				graphics::Sprites::Get(SPRITE_CURSOR).Draw(renderer, position);
			}
		}
	}
}