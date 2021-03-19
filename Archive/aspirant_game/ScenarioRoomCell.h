#pragma once
#include "RoomCell.h"
#include "ScenarioRoomCellFlags.h"
#include "ScenarioObjectInstance.h"
#include "DescriptorManager.h"
namespace aspirant::game
{
	class ScenarioRoomCell : public aspirant::game::RoomCell<ScenarioObjectInstance, ScenarioRoomCellFlags>
	{
	private:
		const DescriptorManager& descriptors;
	protected:
		nlohmann::json CellFlagToJSON(const ScenarioRoomCellFlags&) const;
		nlohmann::json ObjectToJSON(const ScenarioObjectInstance*) const;
		ScenarioRoomCellFlags CellFlagFromJSON(const nlohmann::json&);
		ScenarioObjectInstance* ObjectFromJSON(const nlohmann::json&);
		bool CanCover(const ScenarioObjectInstance*, const ScenarioObjectInstance*) const;
	public:
		ScenarioRoomCell(size_t column, size_t row, const DescriptorManager& descriptors)
			: RoomCell(column, row)
			, descriptors(descriptors)
		{}
	};
}
