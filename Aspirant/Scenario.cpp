#include "Scenario.h"
#include "Utility.h"
namespace aspirant
{
	Scenario::Scenario(const DescriptorManager& descriptors)
		: descriptors(descriptors)
		, rooms()
	{

	}

	void Scenario::Clear()
	{
		tggd::common::Utility::SafeDeleteMap(rooms);
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
			rooms[key] = new ScenarioRoom(descriptors);
			rooms[key]->SetSize(columns, rows);
			rooms[key]->FromJSON(room);
		}
	}

	nlohmann::json Scenario::ToJSON() const
	{
		throw "NOT IMPLEMENTED";
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
			tggd::common::Utility::SafeDelete(rooms[name]);
		}
		rooms[name] = new ScenarioRoom(descriptors);
		rooms[name]->SetSize(columns, rows);
	}

}