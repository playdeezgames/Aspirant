#pragma once
#include <vector>
#include <string>
#include "Game.Scenario.h"
namespace context::editor::Rooms
{
	void UpdateRoomList();
	void SetRoomIndex(size_t);
	size_t GetRoomIndex();
	const std::vector<std::string>& GetRoomList();
	size_t GetRoomCount();
	void NextRoom();
	void PreviousRoom();
	game::Room GetRoom();
}