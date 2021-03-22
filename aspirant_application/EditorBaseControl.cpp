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
		const aspirant::game::CommonDescriptor& descriptor
	)
	{
		if (descriptor.GetType() == TYPE_TERRAIN)
		{
			const aspirant::game::TerrainDescriptor& terrainDescriptor = dynamic_cast<const aspirant::game::TerrainDescriptor&>(descriptor);
			tggd::graphics::SpriteManager::Get(terrainDescriptor.GetSprite()).Draw(renderer, position);
		}
		else if (descriptor.GetType() == TYPE_CREATURE)
		{
			const aspirant::game::CreatureDescriptor& creatureDescriptor = dynamic_cast<const aspirant::game::CreatureDescriptor&>(descriptor);
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