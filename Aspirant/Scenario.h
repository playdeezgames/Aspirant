#pragma once
#include "json.hpp"
#include <map>
#include <string>
#include "Room.h"
#include "ScenarioRoomCell.h"
#include "DescriptorManager.h"
#include "ScenarioRoom.h"
#include <vector>
namespace aspirant
{
	class Scenario
	{
	private:
		const DescriptorManager& descriptors;
		std::map<std::string, ScenarioRoom*> rooms;
		void Clear();
	public:
		Scenario(const DescriptorManager&);
		virtual ~Scenario();
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
		std::vector<std::string> GetRoomKeys() const;
	};
}
