#pragma once
#include "Room.h"
#include "ScenarioRoomCell.h"
namespace aspirant::game
{
	class ScenarioRoom : public aspirant::game::Room<ScenarioRoomCell>
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
		nlohmann::json ToJSON() const;
	};
}
