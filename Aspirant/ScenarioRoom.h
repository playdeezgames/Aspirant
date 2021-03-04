#pragma once
#include "Room.h"
#include "ScenarioRoomCell.h"
namespace aspirant
{
	class ScenarioRoom : public tggd::common::Room<ScenarioRoomCell>
	{
	private:
		const DescriptorManager& descriptors;
	protected:
		ScenarioRoomCell* GenerateRoomCell(size_t column, size_t row)
		{
			return new ScenarioRoomCell(column, row, descriptors);
		}
	public:
		ScenarioRoom(size_t columns, size_t rows, const DescriptorManager& descriptors)
			: descriptors(descriptors)
			, Room(columns, rows)
		{

		}
		void FromJSON(const nlohmann::json&);
	};
}
