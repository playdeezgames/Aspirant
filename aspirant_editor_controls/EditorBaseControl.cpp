#include "EditorBaseControl.h"
#include "TerrainDescriptor.h"
#include "CreatureDescriptor.h"
namespace aspirant::editor::controls
{
	void EditorBaseControl::DrawObject
	(
		SDL_Renderer* renderer, 
		tggd::graphics::XY<int> position, 
		const aspirant::game::ScenarioObjectInstance* obj
	) const
	{
		if (obj)
		{
			auto& descriptor = obj->GetDescriptor();
			if (descriptor.GetType() == "terrain")//TODO: magic string
			{
				const aspirant::game::TerrainDescriptor& terrainDescriptor = dynamic_cast<const aspirant::game::TerrainDescriptor&>(descriptor);
				GetSpriteManager().Get(terrainDescriptor.GetSprite()).Draw(renderer, position);
			}
			else if (descriptor.GetType() == "creature")//TODO: magic string
			{
				const aspirant::game::CreatureDescriptor& creatureDescriptor = dynamic_cast<const aspirant::game::CreatureDescriptor&>(descriptor);
				GetSpriteManager().Get(creatureDescriptor.GetSprite()).Draw(renderer, position);
			}

		}
	}

}