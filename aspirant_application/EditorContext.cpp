#include "EditorContext.h"
#include "Data.JSON.h"
#include "EditorScenarioSelector.h"
#include "ScenarioDescriptorManager.h"
namespace aspirant::editor::context::EditorContext
{
	static aspirant::game::Scenario scenario;

	aspirant::game::Scenario& GetScenario()
	{
		return scenario;
	}

	void SaveScenario()
	{
		data::JSON::Save(aspirant::game::ScenarioDescriptorManager::Get(EditorScenarioSelector::GetIndex())->GetFileName(), GetScenario().ToJSON());
	}

	void LoadScenario()
	{
		aspirant::editor::context::EditorContext::GetScenario()
			.FromJSON(
				data::JSON::Load(
					aspirant::game::ScenarioDescriptorManager::Get(
						aspirant::editor::context::EditorScenarioSelector::GetIndex())
					->GetFileName()));
	}

}
