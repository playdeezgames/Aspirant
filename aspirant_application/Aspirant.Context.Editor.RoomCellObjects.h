#pragma once
#include "ScenarioRoomCell.h"
namespace aspirant::context::editor::RoomCellObjects
{
	size_t GetIndex();
	aspirant::game::ScenarioRoomCell* GetCell();
	void Reset();
}