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
}