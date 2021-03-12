#include "EditorScenarioSelector.h"
#include "Utility.h"
#include "JSONUtility.h"

namespace aspirant::editorui
{
	const aspirant::game::ScenarioDescriptor* EditorScenarioSelector::GetScenarioDescriptor() const
	{
		return scenarios.Get(GetScenarioIndex());
	}

	aspirant::game::ScenarioDescriptor* EditorScenarioSelector::GetScenarioDescriptor()
	{
		return scenarios.Get(GetScenarioIndex());
	}


	void EditorScenarioSelector::SetScenarioIndex(size_t index)
	{
		scenarioIndex = index;
	}

	size_t EditorScenarioSelector::GetScenarioIndex() const
	{
		return scenarioIndex;
	}

	void EditorScenarioSelector::NextScenario()
	{
		SetScenarioIndex(tggd::common::Utility::NextIndex(GetScenarioIndex(), GetScenarios().GetCount()));
	}

	void EditorScenarioSelector::PreviousScenario()
	{
		SetScenarioIndex(tggd::common::Utility::PreviousIndex(GetScenarioIndex(), GetScenarios().GetCount()));
	}

}