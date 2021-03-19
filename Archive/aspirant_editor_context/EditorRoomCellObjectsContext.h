#pragma once
#include "EditorRoomViewContext.h"
#include "EditorRoomListContext.h"
namespace aspirant::editor::context
{
	class EditorRoomCellObjectsContext
	{
		EditorRoomCellObjectsContext() = delete;
		EditorRoomCellObjectsContext(const EditorRoomCellObjectsContext&) = delete;
		EditorRoomCellObjectsContext(EditorRoomCellObjectsContext&&) = delete;
		EditorRoomCellObjectsContext& operator=(const EditorRoomCellObjectsContext&) = delete;
		EditorRoomCellObjectsContext& operator=(EditorRoomCellObjectsContext&&) = delete;
	private:
		EditorRoomListContext& roomList;
		const EditorRoomViewContext& roomView;
		size_t index;
	public:
		EditorRoomCellObjectsContext
		(
			const EditorRoomViewContext&,
			EditorRoomListContext&
		);
		size_t GetIndex() const
		{
			return index;
		}
		const aspirant::game::ScenarioRoomCell* GetCell() const;
		aspirant::game::ScenarioRoomCell* GetCell();
		void Reset();
	};
}