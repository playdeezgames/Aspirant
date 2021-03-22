#pragma once
#include <vector>
#include <string>
#include "Scenario.h"
namespace aspirant::editor::context::EditorRoomListContext
{
	void UpdateRoomList();
	void SetRoomIndex(size_t);
	size_t GetRoomIndex();
	const std::vector<std::string>& GetRoomList();
	size_t GetRoomCount();
	void NextRoom();
	void PreviousRoom();
	aspirant::game::ScenarioRoom* GetRoom();
}