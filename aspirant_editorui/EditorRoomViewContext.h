#pragma once
#include "XY.h"
namespace aspirant::editorui
{
	class EditorRoomViewContext
	{
	private:
		tggd::graphics::XY<size_t> gridSize;
		tggd::graphics::XY<size_t> gridAnchor;
		tggd::graphics::XY<size_t> gridCursor;
	public:
		EditorRoomViewContext
		(
			const tggd::graphics::XY<size_t>&
		);
		const tggd::graphics::XY<size_t>& GetSize() const { return gridSize; }
		const tggd::graphics::XY<size_t>& GetAnchor() const { return gridAnchor; }
		const tggd::graphics::XY<size_t>& GetCursor() const { return gridCursor; }
		void SetAnchor(const tggd::graphics::XY<size_t>& value) { gridAnchor = value; }
		void SetCursor(const tggd::graphics::XY<size_t>& value) { gridCursor = value; }
	};
}
