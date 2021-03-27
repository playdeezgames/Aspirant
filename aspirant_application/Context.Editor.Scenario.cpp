#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
#include <SDL.h>
#include "json.hpp"
namespace context::editor::Scenario
{
	static nlohmann::json scenarioModel;

	game::Scenario Get()
	{
		return game::Scenario(scenarioModel);
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
