#include "Scenario.h"
#include "Common.Utility.h"
namespace aspirant::game
{
	Scenario::Scenario()
		: rooms()
	{

	}

	void Scenario::Clear()
	{
		tggd::common::FinishUtility::SafeDeleteMap(rooms);
	}

	const std::string PROPERTY_ROOMS = "rooms";

	void Scenario::FromJSON(const nlohmann::json& properties)
	{
		Clear();
		auto& items = properties[PROPERTY_ROOMS];
		for (auto& item : items.items())
		{
			auto& room = item.value();
			auto rows = room.size();
			auto columns = room[0].size();
			auto& key = item.key();
			rooms[key] = new ScenarioRoom();
			rooms[key]->SetSize(columns, rows);
			rooms[key]->FromJSON(room);
		}
	}

	nlohmann::json Scenario::ToJSON() const
	{
		nlohmann::json properties;
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

	void Scenario::AddRoom(const std::string& name, size_t columns, size_t rows)
	{
		if (rooms.contains(name))
		{
			tggd::common::FinishUtility::SafeDelete(rooms[name]);
		}
		rooms[name] = new ScenarioRoom();
		rooms[name]->SetSize(columns, rows);
	}

	const ScenarioRoom* Scenario::GetRoom(const std::string& key) const
	{
		auto iter = rooms.find(key);
		return iter->second;
	}

	ScenarioRoom* Scenario::GetRoom(const std::string& key)
	{
		auto iter = rooms.find(key);
		return iter->second;
	}
}