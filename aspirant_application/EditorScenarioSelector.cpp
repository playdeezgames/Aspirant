#include "EditorScenarioSelector.h"
#include "ScenarioDescriptorManager.h"
#include "Utility.h"
namespace aspirant::editor::context::EditorScenarioSelector
{
	static size_t scenarioIndex = 0;
	static void DoBusinessRules()
	{
		if (scenarioIndex >= aspirant::game::ScenarioDescriptorManager::GetCount())
		{
			scenarioIndex = 0;
		}
	}

	void SetIndex(size_t index)
	{
		scenarioIndex = index;
	}

	size_t GetIndex()
	{
		DoBusinessRules();
		return scenarioIndex;
	}

	void EditorScenarioSelector::Next()
	{
		SetIndex(tggd::common::Utility::NextIndex(GetIndex(), aspirant::game::ScenarioDescriptorManager::GetCount()));
	}

	void EditorScenarioSelector::Previous()
	{
		SetIndex(tggd::common::Utility::PreviousIndex(GetIndex(), aspirant::game::ScenarioDescriptorManager::GetCount()));
	}
}