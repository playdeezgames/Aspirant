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
		nlohmann::json avatarModel;
		Avatar avatar;
		std::map<std::string, Room*> rooms;
		void Clear();
	public:
		Scenario();
		virtual ~Scenario();
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
		std::vector<std::string> GetRoomKeys() const;
		void AddRoom(const std::string&, size_t, size_t, const std::string&);
		const Room* GetRoom(const std::string&) const;
		Room* GetRoom(const std::string&);
		const Avatar& GetAvatar() const;
		Avatar& GetAvatar();
	};
}
