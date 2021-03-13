#include "RoomRenderer.h"
#include "TerrainDescriptor.h"
#include "CreatureDescriptor.h"
namespace aspirant::editorui
{
	class RoomRendererPlotter : public tggd::graphics::Plotter<size_t, int>
	{
	public:
		tggd::graphics::XY<int> Plot(const tggd::graphics::XY<size_t> position) const
		{
			return tggd::graphics::XY<int>((int)position.GetX() * 36, (int)position.GetY() * 36);//TODO: magic number
		}
	};

	RoomRenderer::RoomRenderer
	(
		const EditorContext& editorContext,
		const tggd::graphics::SpriteManager& spriteManager
	)
		: editorContext(editorContext)
		, cellPlotter(new RoomRendererPlotter())
		, spriteManager(spriteManager)
	{

	}

	void RoomRenderer::DrawObject
	(
		SDL_Renderer* renderer, 
		const tggd::graphics::XY<int>& position, 
		const aspirant::game::ScenarioObjectInstance* obj
	) const
	{
		if (obj)
		{
			auto& descriptor = obj->GetDescriptor();
			if (descriptor.GetType() == "terrain")//TODO: magic string
			{
				const aspirant::game::TerrainDescriptor& terrainDescriptor = dynamic_cast<const aspirant::game::TerrainDescriptor&>(descriptor);
				spriteManager.Get(terrainDescriptor.GetSprite()).Draw(renderer, position);
			}
			else if (descriptor.GetType() == "creature")//TODO: magic string
			{
				const aspirant::game::CreatureDescriptor& creatureDescriptor = dynamic_cast<const aspirant::game::CreatureDescriptor&>(descriptor);
				spriteManager.Get(creatureDescriptor.GetSprite()).Draw(renderer, position);
			}

		}
	}


	void RoomRenderer::Draw(SDL_Renderer* renderer) const
	{
		auto room = editorContext.GetRoom();
		if (room)
		{
			for (size_t viewRow = 0; viewRow < editorContext.GetRoomView().GetSize().GetY(); ++viewRow)
			{
				for (size_t viewColumn = 0; viewColumn < editorContext.GetRoomView().GetSize().GetX(); ++viewColumn)
				{
					tggd::graphics::XY<size_t> viewPosition =
						tggd::graphics::XY<size_t>
						(
							viewColumn,
							viewRow
						);
					tggd::graphics::XY<size_t> cellPosition = 
						viewPosition + editorContext.GetRoomView().GetAnchor();
					auto cell = room->GetCell(cellPosition.GetX(), cellPosition.GetY());
					if (cell)
					{
						auto obj = cell->GetObject();
						if (obj)
						{
							auto plotPosition = cellPlotter->Plot(viewPosition);
							DrawObject(renderer, plotPosition, obj);
						}
					}
				}
			}
		}
	}
}