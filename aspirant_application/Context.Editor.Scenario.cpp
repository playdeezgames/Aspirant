#include "Aspirant.Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Aspirant.Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
namespace aspirant::context::editor::Scenario
{
	static ::game::Scenario scenario;

	::game::Scenario& Get()
	{
		return scenario;
	}

	void Save()
	{
		data::JSON::Save(
			::game::ScenarioDescriptors::Get(
				::aspirant::context::editor::Scenarios::GetIndex())
			->GetFileName(), 
			Get().ToJSON());
	}

	void Load()
	{
		aspirant::context::editor::Scenario::Get()
			.FromJSON(
				data::JSON::Load(
					::game::ScenarioDescriptors::Get(
						aspirant::context::editor::Scenarios::GetIndex())
					->GetFileName()));
	}

}
