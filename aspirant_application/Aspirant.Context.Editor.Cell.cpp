#pragma once
#include "Aspirant.Context.Editor.Cell.h"
#include "Aspirant.Context.Editor.Rooms.h"
#include "Aspirant.Context.Editor.RoomView.h"
namespace aspirant::context::editor::Cell
{
	static size_t index;

	size_t GetIndex()
	{
		return index;
	}

	::game::Cell* GetCell()
	{
		if (::aspirant::context::editor::Rooms::GetRoom())
		{
			return ::aspirant::context::editor::Rooms::GetRoom()->GetCell(::aspirant::context::editor::RoomView::GetCursor().GetX(), ::aspirant::context::editor::RoomView::GetCursor().GetY());
		}
		return nullptr;
	}

	void Reset()
	{
		auto cell = GetCell();
		index = (cell) ? (cell->GetObjects().size()) : (0);
	}
}