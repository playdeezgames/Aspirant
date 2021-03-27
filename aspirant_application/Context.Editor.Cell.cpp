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

	::game::Cell GetCell()
	{
		return ::context::editor::Rooms::GetRoom().GetCell(::context::editor::RoomView::GetCursor().GetX(), ::context::editor::RoomView::GetCursor().GetY());
	}

	void Reset()
	{
		auto cell = GetCell();
		index = cell.GetObjects().size();
	}
}