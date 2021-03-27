#include "Game.Scenario.h"
#include "Common.Utility.h"
#include "Game.Descriptors.h"
#include "Game.Properties.h"
namespace game
{
	Scenario::Scenario(nlohmann::json& model)
		: model(model)
	{
	}

	std::vector<std::string> Scenario::GetRoomKeys() const
	{
		std::vector<std::string> result;
		for (auto& room : model[game::Properties::ROOMS].items())
		{
			result.push_back(room.key());
		}
		return result;
	}

	void Scenario::AddRoom(const std::string& name, size_t columns, size_t rows, const std::string& terrain)
	{
		model[game::Properties::ROOMS][name] = nlohmann::json();
		auto& room = model[game::Properties::ROOMS][name];
		while (room.size() < rows)
		{
			room.push_back(nlohmann::json());
			auto& row = room.back();
			while (row.size() < columns)
			{
				row.push_back(nlohmann::json());

				auto& cell = row.back();
				cell[game::Properties::OBJECTS] = nlohmann::json();

				auto& objs = cell[game::Properties::OBJECTS];
				objs.push_back(nlohmann::json());

				auto& obj = objs.back();
				obj[common::Properties::TYPE] = terrain;
			}
		}
	}

	Room Scenario::GetRoom(const std::string& key)
	{
		return Room(model[game::Properties::ROOMS][key]);
	}

	Avatar Scenario::GetAvatar()
	{
		return game::Avatar(model[game::Properties::AVATAR]);
	}
}