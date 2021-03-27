#pragma once
#include "json.hpp"
#include <map>
#include <string>
#include "Game.Cell.h"
#include "Game.Descriptors.h"
#include "Game.Room.h"
#include "Game.Avatar.h"
#include <vector>
namespace game
{
	class Scenario
	{
	private:
		nlohmann::json& model;
	public:
		Scenario(nlohmann::json&);
		std::vector<std::string> GetRoomKeys() const;
		void AddRoom(const std::string&, size_t, size_t, const std::string&);
		Room GetRoom(const std::string&);
		Avatar GetAvatar();
	};
}
