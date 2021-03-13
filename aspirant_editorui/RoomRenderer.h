#pragma once
#include <SDL.h>
#include "Drawn.h"
#include "EditorContext.h"
#include "XY.h"
#include "Plotter.h"
#include "SpriteManager.h"
#include "FinishManager.h"
namespace aspirant::editorui
{
	class RoomRenderer: tggd::graphics::Drawn
	{
	private:
		const EditorContext& editorContext;
		tggd::graphics::Plotter<size_t, int>* cellPlotter;
		const tggd::graphics::SpriteManager& spriteManager;
		void DrawObject(SDL_Renderer*, const tggd::graphics::XY<int>&, const aspirant::game::ScenarioObjectInstance*) const;
	public:
		RoomRenderer
		(
			const EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		~RoomRenderer()
		{
			tggd::common::FinishUtility::SafeDelete(cellPlotter);
		}
		void Draw(SDL_Renderer*) const;
	};
}
