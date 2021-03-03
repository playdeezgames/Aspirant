#pragma once
#include "RoomCell.h"
#include "ScenarioRoomCellFlags.h"
#include "ScenarioObjectInstance.h"
namespace aspirant
{
	class ScenarioRoomCell : public tggd::common::RoomCell<ScenarioObjectInstance, ScenarioRoomCellFlags>
	{

	};
}
