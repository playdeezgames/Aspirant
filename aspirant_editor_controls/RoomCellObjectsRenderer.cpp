#include "RoomCellObjectsRenderer.h"
#include "TerrainDescriptor.h"
#include "CreatureDescriptor.h"
namespace aspirant::editor::controls
{
	class RoomCellObjectsPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::graphics::XY<int> Plot(const tggd::graphics::XY<size_t> position) const
		{
			return tggd::graphics::XY<int>(360 + (int)position.GetX() * 36, 0);//TODO: magic numbers
		}
	};

	RoomCellObjectsRenderer::RoomCellObjectsRenderer
	(
		const aspirant::editor::context::EditorContext& editorContext,
		const tggd::graphics::SpriteManager& spriteManager
	)
		: EditorBaseControl(editorContext, spriteManager, new RoomCellObjectsPlotter())
	{

	}

	void RoomCellObjectsRenderer::DrawObject
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


	void RoomCellObjectsRenderer::Draw(SDL_Renderer* renderer) const
	{
		auto& objs = GetEditorContext().GetRoomCellObjects().GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			DrawObject(renderer, GetCellPlotter()->Plot({ column++, 0 }), obj);
		}
		GetSpriteManager().Get("MapCursor").Draw(renderer, GetCellPlotter()->Plot({ GetEditorContext().GetRoomCellObjects().GetIndex(), 0 }));
	}
}