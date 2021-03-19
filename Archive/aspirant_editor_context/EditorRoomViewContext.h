#pragma once
#include "XY.h"
namespace aspirant::editor::context
{
	class EditorRoomViewContext
	{
		EditorRoomViewContext() = delete;
		EditorRoomViewContext(const EditorRoomViewContext&) = delete;
		EditorRoomViewContext(EditorRoomViewContext&&) = delete;
		EditorRoomViewContext& operator=(const EditorRoomViewContext&) = delete;
		EditorRoomViewContext& operator=(EditorRoomViewContext&&) = delete;
	private:
		tggd::common::XY<size_t> gridSize;
		tggd::common::XY<size_t> gridAnchor;
		tggd::common::XY<size_t> gridCursor;
	public:
		EditorRoomViewContext
		(
			const tggd::common::XY<size_t>&
		);
		const tggd::common::XY<size_t>& GetSize() const { return gridSize; }
		const tggd::common::XY<size_t>& GetAnchor() const { return gridAnchor; }
		const tggd::common::XY<size_t>& GetCursor() const { return gridCursor; }
		void SetAnchor(const tggd::common::XY<size_t>& value) { gridAnchor = value; }
		void SetCursor(const tggd::common::XY<size_t>&);
	};
}
