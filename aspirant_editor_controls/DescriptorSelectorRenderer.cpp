#include "DescriptorSelectorRenderer.h"
namespace aspirant::editor::controls
{
	class DescriptorSelectorPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::graphics::XY<int> Plot(const tggd::graphics::XY<size_t> position) const
		{
			return tggd::graphics::XY<int>(360 + (int)position.GetX() * 36, 36 +(int)position.GetY() * 36);//TODO: magic numbers
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

	}
}