#include "Aspirant.Context.Editor.Scenario.h"
#include "Data.JSON.h"
#include "EditorScenarioSelector.h"
#include "ScenarioDescriptorManager.h"
namespace aspirant::context::editor::Scenario
{
	static aspirant::game::Scenario scenario;

	aspirant::game::Scenario& GetScenario()
	{
		return scenario;
	}

	void SaveScenario()
	{
		
		data::JSON::Save(aspirant::game::ScenarioDescriptorManager::Get(::aspirant::editor::context::EditorScenarioSelector::GetIndex())->GetFileName(), GetScenario().ToJSON());
	}

	void LoadScenario()
	{
		aspirant::context::editor::Scenario::GetScenario()
			.FromJSON(
				data::JSON::Load(
					aspirant::game::ScenarioDescriptorManager::Get(
						aspirant::editor::context::EditorScenarioSelector::GetIndex())
					->GetFileName()));
	}

}
