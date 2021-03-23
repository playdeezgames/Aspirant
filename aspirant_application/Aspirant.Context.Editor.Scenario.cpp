#include "Aspirant.Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "Aspirant.Context.Editor.Scenarios.h"
#include "ScenarioDescriptorManager.h"
namespace aspirant::context::editor::Scenario
{
	static aspirant::game::Scenario scenario;

	aspirant::game::Scenario& Get()
	{
		return scenario;
	}

	void Save()
	{
		data::JSON::Save(
			aspirant::game::ScenarioDescriptorManager::Get(
				::aspirant::context::editor::Scenarios::GetIndex())
			->GetFileName(), 
			Get().ToJSON());
	}

	void Load()
	{
		aspirant::context::editor::Scenario::Get()
			.FromJSON(
				data::JSON::Load(
					aspirant::game::ScenarioDescriptorManager::Get(
						aspirant::context::editor::Scenarios::GetIndex())
					->GetFileName()));
	}

}
