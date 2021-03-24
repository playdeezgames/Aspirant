#pragma once
#include "Common.XY.h"
namespace context::editor::RoomView
{
	const common::XY<size_t>& GetSize();
	const common::XY<size_t>& GetAnchor();
	const common::XY<size_t>& GetCursor();
	void SetAnchor(const common::XY<size_t>& value);
	void SetCursor(const common::XY<size_t>&);
}
