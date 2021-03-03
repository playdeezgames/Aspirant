#pragma once
#include "json.hpp"
#include <map>
#include <string>
#include "Room.h"
#include "ScenarioRoomCell.h"
namespace aspirant
{
	typedef tggd::common::Room<ScenarioRoomCell> ScenarioRoom;
	class Scenario
	{
	private:
		std::map<std::string, ScenarioRoom> rooms;
	public:
		Scenario();
		void FromJSON(const nlohmann::json&);
	};
}
