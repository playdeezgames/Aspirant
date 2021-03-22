#pragma once
#include "XY.h"
namespace aspirant::editor::context::EditorRoomViewContext
{
	static tggd::common::XY<size_t> gridSize;
	static tggd::common::XY<size_t> gridAnchor;
	static tggd::common::XY<size_t> gridCursor;
	const tggd::common::XY<size_t>& GetSize()
	{ 
		return gridSize; 
	}
	const tggd::common::XY<size_t>& GetAnchor()
	{ 
		return gridAnchor; 
	}
	const tggd::common::XY<size_t>& GetCursor()
	{ 
		return gridCursor; 
	}
	void SetAnchor(const tggd::common::XY<size_t>& value) 
	{ 
		gridAnchor = value; 
	}
	void SetCursor(const tggd::common::XY<size_t>& value)
	{
		gridCursor = value;
	}
}
