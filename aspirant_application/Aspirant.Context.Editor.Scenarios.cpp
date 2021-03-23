#include "Aspirant.Context.Editor.Scenarios.h"
#include "ScenarioDescriptorManager.h"
#include "Common.Utility.h"
namespace aspirant::context::editor::Scenarios
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

	void Next()
	{
		SetIndex(common::Utility::NextIndex(GetIndex(), aspirant::game::ScenarioDescriptorManager::GetCount()));
	}

	void Previous()
	{
		SetIndex(common::Utility::PreviousIndex(GetIndex(), aspirant::game::ScenarioDescriptorManager::GetCount()));
	}
}