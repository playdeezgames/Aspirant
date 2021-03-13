#include "EditorRoomViewContext.h"
namespace aspirant::editorui
{
	EditorRoomViewContext::EditorRoomViewContext
	(
		const tggd::graphics::XY<size_t>& gridSize
	)
		: gridSize(gridSize)
		, gridAnchor(0,0)
		, gridCursor(0,0)
	{

	}

	void EditorRoomViewContext::SetCursor(const tggd::graphics::XY<size_t>& value)
	{
		gridCursor = value;
		size_t newAnchorX = gridCursor.GetX() - gridSize.GetX() / 2;
		size_t newAnchorY = gridCursor.GetY() - gridSize.GetY() / 2;
		SetAnchor({ newAnchorX, newAnchorY });
	}
}