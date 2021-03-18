#include "DescriptorSelectorRenderer.h"
namespace aspirant::editor::controls
{
	class DescriptorSelectorPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::common::XY<int> Plot(const tggd::common::XY<size_t>& position) const
		{
			return tggd::common::XY<int>(360 + (int)position.GetX() * 36, 36 +(int)position.GetY() * 36);//TODO: magic numbers
		}
	};

	DescriptorSelectorRenderer::DescriptorSelectorRenderer
	(
		const aspirant::editor::context::EditorContext& editorContext,
		const tggd::graphics::SpriteManager& spriteManager
	)
		: EditorBaseControl(editorContext, spriteManager, new DescriptorSelectorPlotter())
	{
	}

	void DescriptorSelectorRenderer::Draw(SDL_Renderer* renderer) const
	{
		const size_t COLUMNS = 7;
		for (size_t idx = 0; idx < GetContext().GetDescriptorSelector().GetCount(); ++idx)
		{
			tggd::common::XY<int> position = GetPlotter()->Plot({ idx % COLUMNS, idx / COLUMNS });
			auto descriptor = GetContext().GetDescriptorSelector().GetDescriptor(idx);
			if (descriptor)
			{
				DrawDescriptor(renderer, position, *descriptor);
			}
			if (idx == GetContext().GetDescriptorSelector().GetIndex())
			{
				GetSpriteManager().Get("MapCursor").Draw(renderer, position);//TODO: magic string
			}
		}
	}
}