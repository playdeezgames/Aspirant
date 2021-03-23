#include "Renderer.Editor.PickDescriptor.h"
#include "Common.XY.h"
#include "Renderer.Editor.Common.h"
#include "Graphics.Sprites.h"
#include "Aspirant.Context.Editor.PickDescriptor.h"
namespace renderer::editor::PickDescriptor
{
	common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return common::XY<int>(360 + (int)position.GetX() * 36, 36 + (int)position.GetY() * 36);
	}

	void Draw(SDL_Renderer* renderer)
	{
		const size_t COLUMNS = 7;
		for (size_t idx = 0; idx < aspirant::context::editor::PickDescriptor::GetCount(); ++idx)
		{
			common::XY<int> position = Plot({ idx % COLUMNS, idx / COLUMNS });
			auto descriptor = aspirant::context::editor::PickDescriptor::GetDescriptor(idx);
			if (descriptor)
			{
				renderer::editor::Common::DrawDescriptor(renderer, position, *descriptor);
			}
			if (idx == aspirant::context::editor::PickDescriptor::GetIndex())
			{
				graphics::Sprites::Get("MapCursor").Draw(renderer, position);//TODO: magic string
			}
		}
	}
}