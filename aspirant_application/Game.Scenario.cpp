#include "Game.Scenario.h"
#include "Common.Utility.h"
#include "Game.Descriptors.h"
namespace game
{
	Scenario::Scenario(nlohmann::json& model)
		: model(model)
	{

	}

	const std::string PROPERTY_ROOMS = "rooms";
	const std::string PROPERTY_AVATAR = "avatar";
	const std::string PROPERTY_TYPE = "type";

	std::vector<std::string> Scenario::GetRoomKeys() const
	{
		std::vector<std::string> result;
		for (auto& room : model[PROPERTY_ROOMS].items())
		{
			result.push_back(room.key());
		}
		return result;
	}

	void Scenario::AddRoom(const std::string& name, size_t columns, size_t rows, const std::string& terrain)
	{
		model[PROPERTY_ROOMS][name] = nlohmann::json();
		auto& room = model[PROPERTY_ROOMS][name];
		while (room.size() < rows)
		{
			room.push_back(nlohmann::json());
			auto& row = room.back();
			while (row.size() < columns)
			{
				row.push_back(nlohmann::json());
				auto& cell = row.back();
				cell.push_back(nlohmann::json());
				auto& obj = cell.back();
				obj[PROPERTY_TYPE] = terrain;
			}
		}
	}

	Room Scenario::GetRoom(const std::string& key)
	{
		return Room(model[PROPERTY_ROOMS][key]);
	}

	Avatar Scenario::GetAvatar()
	{
		return game::Avatar(model[PROPERTY_AVATAR]);
	}
}