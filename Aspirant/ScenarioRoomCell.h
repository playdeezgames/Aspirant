#pragma once
#include "RoomCell.h"
#include "ScenarioRoomCellFlags.h"
#include "ScenarioObjectInstance.h"
#include "DescriptorManager.h"
namespace aspirant
{
	class ScenarioRoomCell : public tggd::common::RoomCell<ScenarioObjectInstance, ScenarioRoomCellFlags>
	{
	private:
		const DescriptorManager& descriptors;
	protected:
		nlohmann::json CellFlagToJSON(const ScenarioRoomCellFlags&);
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
