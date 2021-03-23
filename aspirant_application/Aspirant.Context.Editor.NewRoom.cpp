#include "Aspirant.Context.Editor.NewRoom.h"
namespace aspirant::context::editor::NewRoom
{
	static std::string newRoomName = "";
	static size_t newRoomColumns = 0;
	static size_t newRoomRows = 0;

	void ResetNewRoom()
	{
		newRoomName = "<replace me>";//TODO: magic string
		newRoomColumns = 10;//TODO: magic number
		newRoomRows = 10;//TODO: magic number
	}

	const std::string& GetNewRoomName()
	{
		return newRoomName;
	}

	void AppendNewRoomName(const std::string& text)
	{
		newRoomName += text;
	}

	void ClearNewRoomName()
	{
		newRoomName = "";
	}

	size_t GetNewRoomColumns()
	{
		return newRoomColumns;
	}

	void IncrementNewRoomColumns()
	{
		newRoomColumns++;
	}

	void DecrementNewRoomColumns()
	{
		newRoomColumns = (newRoomColumns <= 1) ? (1) : (newRoomColumns - 1);
	}

	size_t GetNewRoomRows()
	{
		return newRoomRows;
	}

	void IncrementNewRoomRows()
	{
		newRoomRows++;
	}

	void DecrementNewRoomRows()
	{
		newRoomRows = (newRoomRows <= 1) ? (1) : (newRoomRows - 1);
	}
}
