#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include <SDL.h>
#include "json.hpp"
namespace context::editor::Scenario
{
	static nlohmann::json scenarioModel = nlohmann::json();

	game::Scenario Get()
	{
		return game::Scenario(scenarioModel);
	}

	const std::string PROPERTY_AVATAR = "avatar";
	const std::string PROPERTY_ROOMS = "rooms";
	const std::string PROPERTY_ROOM = "room";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

	void Start()
	{
		scenarioModel = nlohmann::json();
		scenarioModel[PROPERTY_AVATAR] = nlohmann::json();
		auto& avatar = scenarioModel[PROPERTY_AVATAR];
		avatar[PROPERTY_ROOM] = "";
		avatar[PROPERTY_X] = 0;
		avatar[PROPERTY_Y] = 0;
		scenarioModel[PROPERTY_ROOMS] = nlohmann::json();
	}

	void Save()
	{
		data::JSON::Save(
			::game::ScenarioDescriptors::Get(
				::context::editor::Scenarios::GetIndex())
			.GetFileName(),
			scenarioModel
			);
	}

	void Load()
	{
		scenarioModel = 
				data::JSON::Load(
					::game::ScenarioDescriptors::Get(
						::context::editor::Scenarios::GetIndex())
					.GetFileName());
	}

}
