#include "EditorBaseControl.h"
#include "SpriteManager.h"
#include "FinishManager.h"
#include "ScenarioObjectInstance.h"
#include "FinishUtility.h"
#include "Game.Descriptor.Creature.h"
#include "Game.Descriptor.Terrain.h"
namespace aspirant::editor::controls::EditorBaseControl
{
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";

	void DrawDescriptor
	(
		SDL_Renderer* renderer,
		tggd::common::XY<int> position,
		const ::game::descriptor::Common& descriptor
	)
	{
		if (descriptor.GetType() == TYPE_TERRAIN)
		{
			const ::game::descriptor::Terrain& terrainDescriptor = dynamic_cast<const ::game::descriptor::Terrain&>(descriptor);
			tggd::graphics::SpriteManager::Get(terrainDescriptor.GetSprite()).Draw(renderer, position);
		}
		else if (descriptor.GetType() == TYPE_CREATURE)
		{
			const ::game::descriptor::Creature& creatureDescriptor = dynamic_cast<const ::game::descriptor::Creature&>(descriptor);
			tggd::graphics::SpriteManager::Get(creatureDescriptor.GetSprite()).Draw(renderer, position);
		}
	}
	void DrawObject
	(
		SDL_Renderer* renderer,
		tggd::common::XY<int> position,
		const aspirant::game::ScenarioObjectInstance* obj
	)
	{
		if (obj)
		{
			DrawDescriptor(renderer, position, obj->GetDescriptor());
		}
	}
}