#include "DescriptorSelectorRenderer.h"
#include "XY.h"
#include "EditorBaseControl.h"
#include "SpriteManager.h"
#include "EditorDescriptorSelectorContext.h"
namespace aspirant::editor::controls::DescriptorSelectorRenderer
{
	tggd::common::XY<int> Plot(const tggd::common::XY<size_t>& position)
	{
		return tggd::common::XY<int>(360 + (int)position.GetX() * 36, 36 + (int)position.GetY() * 36);
	}

	void Draw(SDL_Renderer* renderer)
	{
		const size_t COLUMNS = 7;
		for (size_t idx = 0; idx < aspirant::editor::context::EditorDescriptorSelectorContext::GetCount(); ++idx)
		{
			tggd::common::XY<int> position = Plot({ idx % COLUMNS, idx / COLUMNS });
			auto descriptor = aspirant::editor::context::EditorDescriptorSelectorContext::GetDescriptor(idx);
			if (descriptor)
			{
				aspirant::editor::controls::EditorBaseControl::DrawDescriptor(renderer, position, *descriptor);
			}
			if (idx == aspirant::editor::context::EditorDescriptorSelectorContext::GetIndex())
			{
				tggd::graphics::SpriteManager::Get("MapCursor").Draw(renderer, position);//TODO: magic string
			}
		}
	}
}