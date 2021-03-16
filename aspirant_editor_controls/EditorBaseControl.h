#pragma once
#include "Drawn.h"
#include "EditorContext.h"
#include "Plotter.h"
#include "SpriteManager.h"
#include "FinishManager.h"
namespace aspirant::editor::controls
{
	class EditorBaseControl : public tggd::graphics::Drawn
	{
	private:
		const aspirant::editor::context::EditorContext& editorContext;
		tggd::graphics::Plotter<size_t, int>* cellPlotter;
		const tggd::graphics::SpriteManager& spriteManager;
	protected:
		const aspirant::editor::context::EditorContext& GetEditorContext() const
		{
			return editorContext;
		}
		const tggd::graphics::Plotter<size_t, int>* GetCellPlotter() const
		{
			return cellPlotter;
		}
		const tggd::graphics::SpriteManager& GetSpriteManager() const
		{
			return spriteManager;
		}
		void DrawObject(SDL_Renderer*, tggd::graphics::XY<int>, const aspirant::game::ScenarioObjectInstance*) const;
	public:
		EditorBaseControl
		(
			const aspirant::editor::context::EditorContext& editorContext,
			const tggd::graphics::SpriteManager& spriteManager,
			tggd::graphics::Plotter<size_t, int>* cellPlotter
		)
			: editorContext(editorContext)
			, spriteManager(spriteManager)
			, cellPlotter(cellPlotter)
		{

		}
		virtual ~EditorBaseControl()
		{
			tggd::common::FinishUtility::SafeDelete(cellPlotter);
		}
	};

}