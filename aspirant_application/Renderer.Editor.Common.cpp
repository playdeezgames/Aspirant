#include "Renderer.Editor.Common.h"
#include "SpriteManager.h"
#include "Common.Finishers.h"
#include "Game.Object.Common.h"
#include "FinishUtility.h"
#include "Game.Descriptor.Creature.h"
#include "Game.Descriptor.Terrain.h"
namespace renderer::editor::Common
{
	const std::string TYPE_TERRAIN = "terrain";
	const std::string TYPE_CREATURE = "creature";

	void DrawDescriptor
	(
		SDL_Renderer* renderer,
		common::XY<int> position,
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
		common::XY<int> position,
		const game::object::Common* obj
	)
	{
		if (obj)
		{
			DrawDescriptor(renderer, position, obj->GetDescriptor());
		}
	}
}