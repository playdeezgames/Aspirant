#pragma once
#include "EditorBaseControl.h"
#include "EditorContext.h"
namespace aspirant::editor::controls
{
	class DescriptorSelectorRenderer: public EditorBaseControl<aspirant::editor::context::EditorContext>
	{
		DescriptorSelectorRenderer() = delete;
		DescriptorSelectorRenderer(const DescriptorSelectorRenderer&) = delete;
		DescriptorSelectorRenderer(DescriptorSelectorRenderer&&) = delete;
		DescriptorSelectorRenderer& operator=(const DescriptorSelectorRenderer&) = delete;
		DescriptorSelectorRenderer& operator=(DescriptorSelectorRenderer&&) = delete;
	public:
		DescriptorSelectorRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}