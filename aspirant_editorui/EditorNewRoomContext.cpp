#include "EditorNewRoomContext.h"
namespace aspirant::editorui
{
	void EditorNewRoomContext::ResetNewRoom()
	{
		newRoomName = "<replace me>";//TODO: magic string
		newRoomColumns = 10;//TODO: magic number
		newRoomRows = 10;//TODO: magic number
	}

	const std::string& EditorNewRoomContext::GetNewRoomName() const
	{
		return newRoomName;
	}

	void EditorNewRoomContext::AppendNewRoomName(const std::string& text)
	{
		newRoomName += text;
	}

	void EditorNewRoomContext::ClearNewRoomName()
	{
		newRoomName = "";
	}

	size_t EditorNewRoomContext::GetNewRoomColumns() const
	{
		return newRoomColumns;
	}

	void EditorNewRoomContext::IncrementNewRoomColumns()
	{
		newRoomColumns++;
	}

	void EditorNewRoomContext::DecrementNewRoomColumns()
	{
		newRoomColumns = (newRoomColumns <= 1) ? (1) : (newRoomColumns - 1);
	}

	size_t EditorNewRoomContext::GetNewRoomRows() const
	{
		return newRoomRows;
	}

	void EditorNewRoomContext::IncrementNewRoomRows()
	{
		newRoomRows++;
	}

	void EditorNewRoomContext::DecrementNewRoomRows()
	{
		newRoomRows = (newRoomRows <= 1) ? (1) : (newRoomRows - 1);
	}

}