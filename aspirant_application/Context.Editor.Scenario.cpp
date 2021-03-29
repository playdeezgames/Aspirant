#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include <SDL.h>
#include "json.hpp"
#include "Common.Properties.h"
#include "Game.Properties.h"
namespace context::editor::Scenario
{
	static nlohmann::json scenarioModel = nlohmann::json();

	game::Scenario Get()
	{
		return game::Scenario(scenarioModel);
	}

	void Start()
	{
		scenarioModel = nlohmann::json();
		scenarioModel[game::Properties::AVATAR] = nlohmann::json();
		auto& avatar = scenarioModel[game::Properties::AVATAR];
		avatar[game::Properties::ROOM] = "";
		avatar[common::Properties::X] = 0;
		avatar[common::Properties::Y] = 0;
		scenarioModel[game::Properties::ROOMS] = nlohmann::json();
	}

	void Save()
	{
		data::JSON::Save(
			::game::ScenarioDescriptors::Get(
				::context::editor::Scenarios::GetIndex())
			.value()
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
					.value()
					.GetFileName());
	}

}
