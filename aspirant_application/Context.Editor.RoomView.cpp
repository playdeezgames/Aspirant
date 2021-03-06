#pragma once
#include "Context.Editor.RoomView.h"
#include "Common.XY.h"
namespace context::editor::RoomView
{
	static common::XY<size_t> gridSize = { 10,10 };
	static common::XY<size_t> gridAnchor;
	static common::XY<size_t> gridCursor;
	const common::XY<size_t>& GetSize()
	{ 
		return gridSize; 
	}
	const common::XY<size_t>& GetAnchor()
	{ 
		return gridAnchor; 
	}
	const common::XY<size_t>& GetCursor()
	{ 
		return gridCursor; 
	}
	void SetAnchor(const common::XY<size_t>& value) 
	{ 
		gridAnchor = value; 
	}
	void SetCursor(const common::XY<size_t>& value)
	{
		gridCursor = value;
		size_t newAnchorX = gridCursor.GetX() - gridSize.GetX() / 2;
		size_t newAnchorY = gridCursor.GetY() - gridSize.GetY() / 2;
		SetAnchor({ newAnchorX, newAnchorY });
	}
}
