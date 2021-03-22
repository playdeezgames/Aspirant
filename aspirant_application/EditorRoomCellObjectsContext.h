#pragma once
#include "ScenarioRoomCell.h"
namespace aspirant::editor::context::EditorRoomCellObjectsContext
{
	size_t GetIndex();
	aspirant::game::ScenarioRoomCell* GetCell();
	void Reset();
}