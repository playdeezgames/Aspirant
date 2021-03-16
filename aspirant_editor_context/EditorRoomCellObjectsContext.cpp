#include "EditorRoomCellObjectsContext.h"
namespace aspirant::editor::context
{
	EditorRoomCellObjectsContext::EditorRoomCellObjectsContext
	(
		const EditorRoomViewContext& roomView,
		EditorRoomListContext& roomList
	)
		: roomView(roomView)
		, roomList(roomList)
		, index(0)
	{

	}

	const aspirant::game::ScenarioRoomCell* EditorRoomCellObjectsContext::GetCell() const
	{
		if (roomList.GetRoom())
		{
			return roomList.GetRoom()->GetCell(roomView.GetCursor().GetX(), roomView.GetCursor().GetY());
		}
		return nullptr;
	}

	aspirant::game::ScenarioRoomCell* EditorRoomCellObjectsContext::GetCell()
	{
		if (roomList.GetRoom())
		{
			return roomList.GetRoom()->GetCell(roomView.GetCursor().GetX(), roomView.GetCursor().GetY());
		}
		return nullptr;
	}

}