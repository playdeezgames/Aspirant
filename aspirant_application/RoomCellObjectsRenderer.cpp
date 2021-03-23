#include "RoomCellObjectsRenderer.h"
#include "Common.XY.h"
#include "Renderer.Editor.Common.h"
#include "EditorRoomCellObjectsContext.h"
#include "SpriteManager.h"
namespace aspirant::editor::controls::RoomCellObjectsRenderer
{
	common::XY<int> Plot(const common::XY<size_t>& position)
	{
		return { 360 + (int)position.GetX() * 36, 0 };//TODO: magic numbers
	}

	void Draw(SDL_Renderer* renderer)
	{
		auto& objs = aspirant::editor::context::EditorRoomCellObjectsContext::GetCell()->GetObjects();
		size_t column = 0;
		for (auto& obj : objs)
		{
			renderer::editor::Common::DrawObject(renderer, Plot({ column++, 0 }), obj);
		}
		tggd::graphics::SpriteManager::Get("MapCursor").Draw(renderer, Plot({ aspirant::editor::context::EditorRoomCellObjectsContext::GetIndex(), 0 }));
	}
}