#include "Game.Scenario.h"
#include "Common.Utility.h"
#include "Game.Descriptors.h"
namespace game
{
	Scenario::Scenario()
		: rooms()
	{

	}

	void Scenario::Clear()
	{
		common::Finisher::Finish(rooms);
	}

	const std::string PROPERTY_ROOMS = "rooms";
	const std::string PROPERTY_AVATAR = "avatar";

	void Scenario::FromJSON(const nlohmann::json& properties)
	{
		Clear();
		avatar.FromJSON(properties[PROPERTY_AVATAR]);
		auto& items = properties[PROPERTY_ROOMS];
		for (auto& item : items.items())
		{
			auto& room = item.value();
			auto rows = room.size();
			auto columns = room[0].size();
			auto& key = item.key();
			rooms[key] = new Room();
			rooms[key]->SetSize(columns, rows);
			rooms[key]->FromJSON(room);
		}
	}

	nlohmann::json Scenario::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_AVATAR] = avatar.ToJSON();
		for (auto& room : rooms)
		{
			properties[PROPERTY_ROOMS][room.first] = room.second->ToJSON();
		}
		return properties;
	}

	Scenario::~Scenario()
	{
		Clear();
	}

	std::vector<std::string> Scenario::GetRoomKeys() const
	{
		std::vector<std::string> result;
		for (auto& room : rooms)
		{
			result.push_back(room.first);
		}
		return result;
	}

	void Scenario::AddRoom(const std::string& name, size_t columns, size_t rows, const std::string& terrain)
	{
		if (rooms.contains(name))
		{
			common::Finisher::Finish(rooms[name]);
		}
		rooms[name] = new Room();
		rooms[name]->SetSize(columns, rows);
		for (size_t column = 0; column < columns; ++column)
		{
			for (size_t row = 0; row < rows; ++row)
			{
				rooms[name]->GetCell(column, row)->AddObject(game::Descriptors::Get(terrain)->CreateObject());
			}
		}
	}

	const Room* Scenario::GetRoom(const std::string& key) const
	{
		auto iter = rooms.find(key);
		return iter->second;
	}

	Room* Scenario::GetRoom(const std::string& key)
	{
		auto iter = rooms.find(key);
		return iter->second;
	}

	const Avatar& Scenario::GetAvatar() const
	{
		return avatar;
	}

	Avatar& Scenario::GetAvatar()
	{
		return avatar;
	}

}