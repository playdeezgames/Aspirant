#include "Renderer.Editor.Common.h"
#include "Graphics.Sprites.h"
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
		graphics::Sprites::Get(descriptor.GetSprite()).Draw(renderer, position);
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