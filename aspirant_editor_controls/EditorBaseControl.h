#pragma once
#include "Drawn.h"
#include "Plotter.h"
#include "SpriteManager.h"
#include "FinishManager.h"
#include "ScenarioObjectInstance.h"
#include "FinishUtility.h"
#include "CreatureDescriptor.h"
#include "TerrainDescriptor.h"
namespace aspirant::editor::controls
{
	template<typename TContext>
	class EditorBaseControl : public tggd::graphics::Drawn
	{
	private:
		const TContext& context;
		tggd::graphics::Plotter<size_t, int>* plotter;
		const tggd::graphics::SpriteManager& spriteManager;
		const std::string TYPE_TERRAIN = "terrain";
		const std::string TYPE_CREATURE = "creature";
	protected:
		const TContext& GetContext() const
		{
			return context;
		}
		const tggd::graphics::Plotter<size_t, int>* GetPlotter() const
		{
			return plotter;
		}
		const tggd::graphics::SpriteManager& GetSpriteManager() const
		{
			return spriteManager;
		}
		void DrawDescriptor
		(
			SDL_Renderer* renderer,
			tggd::common::XY<int> position,
			const aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>& descriptor
		) const
		{
			if (descriptor.GetType() == TYPE_TERRAIN)
			{
				const aspirant::game::TerrainDescriptor& terrainDescriptor = dynamic_cast<const aspirant::game::TerrainDescriptor&>(descriptor);
				GetSpriteManager().Get(terrainDescriptor.GetSprite()).Draw(renderer, position);
			}
			else if (descriptor.GetType() == TYPE_CREATURE)
			{
				const aspirant::game::CreatureDescriptor& creatureDescriptor = dynamic_cast<const aspirant::game::CreatureDescriptor&>(descriptor);
				GetSpriteManager().Get(creatureDescriptor.GetSprite()).Draw(renderer, position);
			}
		}
		void DrawObject
		(
			SDL_Renderer* renderer, 
			tggd::common::XY<int> position,
			const aspirant::game::ScenarioObjectInstance* obj
		) const
		{
			if (obj)
			{
				DrawDescriptor(renderer, position, obj->GetDescriptor());
			}
		}

	public:
		EditorBaseControl
		(
			const TContext& context,
			const tggd::graphics::SpriteManager& spriteManager,
			tggd::graphics::Plotter<size_t, int>* plotter
		)
			: context(context)
			, spriteManager(spriteManager)
			, plotter(plotter)
		{

		}
		virtual ~EditorBaseControl()
		{
			tggd::common::FinishUtility::SafeDelete(plotter);
		}
	};

}