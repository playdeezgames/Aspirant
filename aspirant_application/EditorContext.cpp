#include "EditorContext.h"
#include "JSONUtility.h"
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
		tggd::data::JSONUtility::SaveJSON(aspirant::game::ScenarioDescriptorManager::Get(EditorScenarioSelector::GetIndex())->GetFileName(), GetScenario().ToJSON());
	}

	void LoadScenario()
	{
		aspirant::editor::context::EditorContext::GetScenario()
			.FromJSON(
				tggd::data::JSONUtility::LoadJSON(
					aspirant::game::ScenarioDescriptorManager::Get(
						aspirant::editor::context::EditorScenarioSelector::GetIndex())
					->GetFileName()));
	}

}
