#pragma once
#include <string>
namespace aspirant::context::editor::NewRoom
{
	void ResetNewRoom();
	const std::string& GetNewRoomName();
	void AppendNewRoomName(const std::string&);
	void ClearNewRoomName();
	size_t GetNewRoomColumns();
	void IncrementNewRoomColumns();
	void DecrementNewRoomColumns();
	size_t GetNewRoomRows();
	void IncrementNewRoomRows();
	void DecrementNewRoomRows();
}
