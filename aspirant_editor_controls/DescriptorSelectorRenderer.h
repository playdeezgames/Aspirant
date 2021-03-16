#pragma once
#include "EditorBaseControl.h"
namespace aspirant::editor::controls
{
	class DescriptorSelectorRenderer: public EditorBaseControl
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