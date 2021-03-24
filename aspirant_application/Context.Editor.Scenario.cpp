#include "Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Context.Editor.Scenarios.h"
#include "Game.ScenarioDescriptors.h"
namespace context::editor::Scenario
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
				::context::editor::Scenarios::GetIndex())
			->GetFileName(), 
			Get().ToJSON());
	}

	void Load()
	{
		::context::editor::Scenario::Get()
			.FromJSON(
				data::JSON::Load(
					::game::ScenarioDescriptors::Get(
						::context::editor::Scenarios::GetIndex())
					->GetFileName()));
	}

}
