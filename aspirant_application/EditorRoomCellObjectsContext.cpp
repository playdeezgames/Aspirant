#pragma once
#include "EditorRoomCellObjectsContext.h"
#include "EditorRoomListContext.h"
#include "EditorRoomViewContext.h"
namespace aspirant::editor::context::EditorRoomCellObjectsContext
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}

	aspirant::game::ScenarioRoomCell* GetCell()
	{
		if (EditorRoomListContext::GetRoom())
		{
			return EditorRoomListContext::GetRoom()->GetCell(EditorRoomViewContext::GetCursor().GetX(), EditorRoomViewContext::GetCursor().GetY());
		}
		return nullptr;
	}

	void Reset()
	{
		auto cell = GetCell();
		index = (cell) ? (cell->GetObjects().size()) : (0);
	}
}