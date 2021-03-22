#pragma once
#include "XY.h"
namespace aspirant::editor::context::EditorRoomViewContext
{
	const tggd::common::XY<size_t>& GetSize();
	const tggd::common::XY<size_t>& GetAnchor();
	const tggd::common::XY<size_t>& GetCursor();
	void SetAnchor(const tggd::common::XY<size_t>& value);
	void SetCursor(const tggd::common::XY<size_t>&);
}
