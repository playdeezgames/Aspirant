#pragma once
#include "EditorBaseControl.h"
#include "EditorContext.h"
namespace aspirant::editor::controls
{
	class DescriptorSelectorRenderer: public EditorBaseControl<aspirant::editor::context::EditorContext>
	{
	public:
		DescriptorSelectorRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		void Draw(SDL_Renderer*) const;
	};
}