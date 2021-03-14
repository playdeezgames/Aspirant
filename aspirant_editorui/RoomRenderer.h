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
		const aspirant::editor::context::EditorContext& editorContext;
		tggd::graphics::Plotter<size_t, int>* cellPlotter;
		const tggd::graphics::SpriteManager& spriteManager;
		void DrawObject(SDL_Renderer*, const tggd::graphics::XY<int>&, const aspirant::game::ScenarioObjectInstance*) const;
		void DrawCell(SDL_Renderer*, const tggd::graphics::XY<size_t>&, const aspirant::game::ScenarioRoomCell*) const;
		void DrawRoom(SDL_Renderer*, const aspirant::game::ScenarioRoom*) const;
		void DrawMapCursor(SDL_Renderer*) const;
	public:
		RoomRenderer
		(
			const aspirant::editor::context::EditorContext&,
			const tggd::graphics::SpriteManager&
		);
		~RoomRenderer()
		{
			tggd::common::FinishUtility::SafeDelete(cellPlotter);
		}
		void Draw(SDL_Renderer*) const;
	};
}
