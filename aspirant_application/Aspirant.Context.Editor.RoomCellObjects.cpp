#pragma once
#include "Aspirant.Context.Editor.RoomCellObjects.h"
#include "EditorRoomListContext.h"
#include "EditorRoomViewContext.h"
namespace aspirant::context::editor::RoomCellObjects
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}

	aspirant::game::ScenarioRoomCell* GetCell()
	{
		if (::aspirant::editor::context::EditorRoomListContext::GetRoom())
		{
			return ::aspirant::editor::context::EditorRoomListContext::GetRoom()->GetCell(::aspirant::editor::context::EditorRoomViewContext::GetCursor().GetX(), ::aspirant::editor::context::EditorRoomViewContext::GetCursor().GetY());
		}
		return nullptr;
	}

	void Reset()
	{
		auto cell = GetCell();
		index = (cell) ? (cell->GetObjects().size()) : (0);
	}
}