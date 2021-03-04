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
		ScenarioRoomCell* GenerateRoomCell(size_t column, size_t row);
	public:
		ScenarioRoom(const DescriptorManager& descriptors)
			: Room()
			, descriptors(descriptors)
		{

		}
		void FromJSON(const nlohmann::json&);
	};
}
