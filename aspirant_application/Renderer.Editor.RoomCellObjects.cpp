#include "Renderer.Editor.RoomCellObjects.h"
#include "Common.XY.h"
#include "Renderer.Editor.Common.h"
#include "Aspirant.Context.Editor.RoomCellObjects.h"
#include "SpriteManager.h"
namespace renderer::editor::RoomCellObjects
{
	common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return { 360 + (int)position.GetX() * 36, 0 };//TODO: magic numbers
	}

	void Draw(SDL_Renderer* renderer)
	{
		auto& objs = aspirant::context::editor::RoomCellObjects::GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			renderer::editor::Common::DrawObject(renderer, Plot({ column++, 0 }), obj);
		}
		tggd::graphics::SpriteManager::Get("MapCursor").Draw(renderer, Plot({ aspirant::context::editor::RoomCellObjects::GetIndex(), 0 }));
	}
}