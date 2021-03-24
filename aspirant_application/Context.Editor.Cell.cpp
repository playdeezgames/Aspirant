#pragma once
#include "Context.Editor.Cell.h"
#include "Context.Editor.Rooms.h"
#include "Context.Editor.RoomView.h"
namespace context::editor::Cell
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}

	::game::Cell* GetCell()
	{
		if (::context::editor::Rooms::GetRoom())
		{
			return ::context::editor::Rooms::GetRoom()->GetCell(::context::editor::RoomView::GetCursor().GetX(), ::context::editor::RoomView::GetCursor().GetY());
		}
		return nullptr;
	}

	void Reset()
	{
		auto cell = GetCell();
		index = (cell) ? (cell->GetObjects().size()) : (0);
	}
}