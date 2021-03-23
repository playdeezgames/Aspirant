#pragma once
#include "Common.XY.h"
namespace aspirant::editor::context::EditorRoomViewContext
{
	const common::XY<size_t>& GetSize();
	const common::XY<size_t>& GetAnchor();
	const common::XY<size_t>& GetCursor();
	void SetAnchor(const common::XY<size_t>& value);
	void SetCursor(const common::XY<size_t>&);
}
