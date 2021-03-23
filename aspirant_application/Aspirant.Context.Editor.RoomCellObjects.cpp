#pragma once
#include "Aspirant.Context.Editor.RoomCellObjects.h"
#include "Aspirant.Context.Editor.RoomList.h"
#include "Aspirant.Context.Editor.RoomView.h"
namespace aspirant::context::editor::RoomCellObjects
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}

	::game::Cell* GetCell()
	{
		if (::aspirant::context::editor::RoomList::GetRoom())
		{
			return ::aspirant::context::editor::RoomList::GetRoom()->GetCell(::aspirant::context::editor::RoomView::GetCursor().GetX(), ::aspirant::context::editor::RoomView::GetCursor().GetY());
		}
		return nullptr;
	}

	void Reset()
	{
		auto cell = GetCell();
		index = (cell) ? (cell->GetObjects().size()) : (0);
	}
}