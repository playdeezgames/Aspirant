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
		nlohmann::json avatarModel;
		std::map<std::string, Room*> rooms;
		void Clear();
	public:
		Scenario(nlohmann::json&);
		virtual ~Scenario();
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
		std::vector<std::string> GetRoomKeys() const;
		void AddRoom(const std::string&, size_t, size_t, const std::string&);
		const Room* GetRoom(const std::string&) const;
		Room* GetRoom(const std::string&);
		Avatar GetAvatar();
	};
}
